#include "ros/ros.h"
#include <vector>
#include <stdio.h>
#include "std_msgs/String.h"
#include "prog_pkg/Goal.h"
#include "prog_pkg/Picker.h"
#include "prog_pkg/Deliver.h"
#include "prog_pkg/Arrived.h"
#include "prog_pkg/IsLoaded.h"
#include "geometry_msgs/PoseStamped.h"
#include "tf/tf.h"
#include "tf2_msgs/TFMessage.h"
#include <sstream>
#include "tf2_ros/transform_listener.h"
#include "geometry_msgs/TransformStamped.h"
#include "nav_msgs/Odometry.h"
#include "sensor_msgs/LaserScan.h"

// Flag di controllo
int message_published = 0;
int info_published = 0;
int pick_position_set = 0;
int cruising = 0;
int reached_goal = 0;
int loaded_parcel = 0;
int picked_parcel = 0;
int is_asked = 0;
int is_delivered = 0;

// Vettori di posizione
std::vector<float> picker_position(2,0);
std::vector<float> delivery_position(2,0);
std::vector<float> old_position(2,0);
std::vector<float> current_position(2,0);

// Altre variabili globali

geometry_msgs::PoseStamped new_goal_msg;
tf2_ros::Buffer tfBuffer;
size_t n = 10;
float T = 1;

/*
* Funzione che prende in input un messaggio picker con le coordinate
* e setta un nuovo goal
*/

void SetGoal_Callback(const prog_pkg::Picker& new_goal){

    /*
    * Per settare una posizione che non faccia crashare il programma
    * usare la funzione 2D Nav Goal di rviz e stampare le coordinate con echo
    */

    new_goal_msg.header.seq = n;
    n++;

    // Comunicazione del tempo corrente

    new_goal_msg.header.stamp = ros::Time::now();
    new_goal_msg.header.frame_id = "map";

    new_goal_msg.pose.position.x = new_goal.x;
    new_goal_msg.pose.position.y = new_goal.y;
    new_goal_msg.pose.position.z = 0;

    /*
    * x = 53.88 
    * y = 18.0
    * theta = 0.02
    */

    new_goal_msg.pose.orientation.x = 0;
    new_goal_msg.pose.orientation.y = 0;
    new_goal_msg.pose.orientation.z = 0;
    new_goal_msg.pose.orientation.w = new_goal.theta;

    // Per chiamare la callback solo una volta

    message_published = 1;

    // Inizio lo spostamento

    cruising = 1;

    // Salvare le coordinate del goal

    picker_position[0] = new_goal_msg.pose.position.x;
    picker_position[1] = new_goal_msg.pose.position.y;

}

/*
* Funzione che verifica la posizione del robot verificando se posso
* trasformare dal frame della mappa al base_link, se affermativo, 
* prendo la trasformata e la metto dentro transformStamped
*/

void position_CallBack(const tf2_msgs::TFMessage& tf)
{
    int transform_ok;
    transform_ok = tfBuffer.canTransform("map", "base_link",ros::Time(0));

    if (transform_ok != 0)
    {
        geometry_msgs::TransformStamped transfromStamped;
        transfromStamped = tfBuffer.lookupTransform("map", "base_link", ros::Time(0));

        // Aggiorno la posizione corretta

        current_position[0] = transfromStamped.transform.translation.x;
        current_position[1] = transfromStamped.transform.translation.y;

    }
    
}

void navigationCallback(const ros::TimerEvent& event)
{
    // eseguo il controllo solo se mi muovo

    if (cruising != 0)
    {
        ROS_INFO("Controllo se mi muovo");
        float distance;
        distance = sqrt(pow(current_position[0] - old_position[0],2) + pow(current_position[1] - old_position[1],2));

        /*
        * Se non mi sono spostato di una certa treshold  
        * allora comunico che mi sono bloccato
        */

        if (distance < 0.8)
        {
            ROS_INFO("Sono bloccato!");
        }
        if (sqrt(pow(current_position[0] - picker_position[0],2) + pow(current_position[1] - picker_position[1],2)) < 1.5)
        {
            ROS_INFO("Arrivato a destinazione");
            cruising = 0;
            reached_goal = 1;
        }
    }
    
}

void elapsedCallback(const ros::TimerEvent& event)
{
    // eseguo il controllo solo se mi muovo

    if (cruising != 0)
    {
        ROS_INFO("Controllo se è passato troppo tempo");
        float distance;
        distance = sqrt(pow(current_position[0] - picker_position[0],2) + pow(current_position[1] - picker_position[1],2));

        if (distance > 0.5)
        {
            ROS_INFO("TIMEOUT: Non posso raggiungere l'obiettivo");
        }
        
    }
}

int main(int argc, char **argv){

    std::cout << R"(
   _____      __     ______            __
  / ___/___  / /_   / ____/___  ____ _/ /
  \__ \/ _ \/ __/  / / __/ __ \/ __ `/ / 
 ___/ /  __/ /_   / /_/ / /_/ / /_/ / /  
/____/\___/\__/   \____/\____/\__,_/_/                                            
)" << '\n';

    ros::init(argc,argv,"set_goal_test");

    ros::NodeHandle n;

    ros::Rate loop_rate(T);

    ros::Subscriber sub_picker = n.subscribe("picker",1000,SetGoal_Callback);

    ros::Publisher pub = n.advertise<geometry_msgs::PoseStamped>("/move_base_simple/goal",1000);

    tf2_ros::TransformListener tfListener(tfBuffer);

    ros::Publisher pub_arrived = n.advertise<prog_pkg::Arrived>("arrived",1000);

    ros::Publisher pub_delivery = n.advertise<prog_pkg::Arrived>("delivered",1000); 

    ros::Subscriber sub_tf = n.subscribe("tf",1000,position_CallBack);

    ros::ServiceClient client = n.serviceClient<prog_pkg::IsLoaded>("is_loaded");

    ros::ServiceClient del_client = n.serviceClient<prog_pkg::IsLoaded>("is_picked_up");

    prog_pkg::IsLoaded srv;

    prog_pkg::IsLoaded del_srv;


    /* 
    *  Controllo con dei tempi prefissati lo stato della navigazione
    *  del robot
    */

    ros::Timer check_navigation = n.createTimer(ros::Duration(0.5), navigationCallback);
    ros::Timer elapsed_time = n.createTimer(ros::Duration(50), elapsedCallback);

    int count = 0;
    while (ros::ok())
    {
        // Viene inviato un solo messaggio con le coordinate
        if(message_published != 0)
        {
            ROS_INFO("Publishing a new goal position");
            pub.publish(new_goal_msg);
            message_published = 0;
        }

        if (reached_goal == 1 && is_asked == 0)
        {
            prog_pkg::Arrived arrived;
            arrived.reached_goal = 1;   
            ROS_INFO("Comunico al client che sono arrivato");
            pub_arrived.publish(arrived);
            
                if (client.call(srv))
                {
                    loaded_parcel = srv.response.result;
                    ROS_INFO("L'utente ha caricato il pacco: [%d]", loaded_parcel);
                }
                else
                {
                    ROS_ERROR("Impossibile comunicare con il client");
                    return 1;
                }
                
            is_asked = 1;
            reached_goal = 0;
        }
        else if (reached_goal == 1 && is_delivered == 0)
        {
            prog_pkg::Arrived del_notification;
            del_notification.reached_goal = 1;
            ROS_INFO("Comunico al deliver che sono arrivato");
            pub_delivery.publish(del_notification);

            if (del_client.call(del_srv))
            {
                picked_parcel = srv.response.result;
                ROS_INFO("L'utente ha ritirato il pacco: [%d]", loaded_parcel);
            }
            else
            {
                ROS_ERROR("Impossibile comunicare con il client");
                return 1;
            }
            
            is_delivered = 1;
            reached_goal = 0;
        }
        
        

        ros::spinOnce();

        loop_rate.sleep();

        ++count;
    }
    

    ros::spin();
    

    return 0;

}