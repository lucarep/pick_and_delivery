#include "ros/ros.h"
#include <vector>
#include <stdio.h>
#include "std_msgs/String.h"
#include "prog_pkg/Goal.h"
#include "prog_pkg/Picker.h"
#include "prog_pkg/Deliver.h"
#include "geometry_msgs/PoseStamped.h"
#include "tf/tf.h"
#include "tf2_msgs/TFMessage.h"
#include <sstream>
#include "tf2_ros/transform_listener.h"
#include "geometry_msgs/TransformStamped.h"
#include "nav_msgs/Odometry.h"
#include "sensor_msgs/LaserScan.h"

// Flag di controllo
int info_published = 0;
int info2_published = 0;
int cruising = 0;
int reached_goal = 0;

// Vettori di posizione
std::vector<float> pick_position(2,0);
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

void pickerCallback(const prog_pkg::Picker& picker)
{
    if (info_published == 0)
    {
        ROS_INFO("ricevo valore picker x di: [%f]",picker.x);
        ROS_INFO("ricevo valore picker y di: [%f]",picker.y);
        ROS_INFO("ricevo valore picker theta di: [%f]",picker.theta);
        std::cout << ("----------------------------------------") << '\n';
        info_published++;
    }

    new_goal_msg.header.seq = n;
    n++;

    // Comunicazione del tempo corrente

    new_goal_msg.header.stamp = ros::Time::now();
    new_goal_msg.header.frame_id = "map";

    new_goal_msg.pose.position.x = picker.x;
    new_goal_msg.pose.position.y = picker.y;
    new_goal_msg.pose.position.z = 0;

    /*
    * x = 53.88 
    * y = 18.0
    * theta = 0.02
    */

    new_goal_msg.pose.orientation.x = 0;
    new_goal_msg.pose.orientation.y = 0;
    new_goal_msg.pose.orientation.z = 0;
    new_goal_msg.pose.orientation.w = picker.theta;

    // Inizio lo spostamento

    cruising = 1;

    // Salvare le coordinate del goal

    pick_position[0] = new_goal_msg.pose.position.x;
    pick_position[1] = new_goal_msg.pose.position.y;
   
}

/*
* Funzione che prende in input un messaggio di deliver con le coordinate
* e setta un nuovo goal
*/

void deliverCallback(const prog_pkg::Deliver& deliver)
{
    if (info2_published == 0)
    {
        ROS_INFO("ricevo valore deliver x di: [%f]",deliver.x);
        ROS_INFO("ricevo valore deliver y di: [%f]",deliver.y);
        ROS_INFO("ricevo valore deliver theta di: [%f]",deliver.theta);
        info2_published++;
    }
    
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
        if (sqrt(pow(current_position[0] - pick_position[0],2) + pow(current_position[1] - pick_position[1],2)) < 1.5)
        {
            ROS_INFO("Arrivato a destinazione");
            cruising = 0;
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
        distance = sqrt(pow(current_position[0] - pick_position[0],2) + pow(current_position[1] - pick_position[1],2));

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

    tf2_ros::TransformListener tfListener(tfBuffer);

    ros::Rate loop_rate(T);

    ros::NodeHandle n;

    ros::Subscriber sub_picker = n.subscribe("picker",1000,pickerCallback);

    ros::Subscriber sub_deliver = n.subscribe("deliver",1000,deliverCallback);

    ros::Subscriber sub_tf = n.subscribe("tf",1000,position_CallBack);

    /* 
    *  Controllo con dei tempi prefissati lo stato della navigazione
    *  del robot
    */

    ros::Timer check_navigation = n.createTimer(ros::Duration(0.5), navigationCallback);
    ros::Timer elapsed_time = n.createTimer(ros::Duration(50), elapsedCallback);

    ros::spin();

    return 0;

}