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

// Dichiarazione variabili globali

std::vector<float> target_position(2,0);
std::vector<float> old_position(2,0);
std::vector<float> current_position(2,0);

geometry_msgs::PoseStamped new_goal_msg;
tf2_ros::Buffer tfBuffer;

size_t n = 10;
int message_published = 0;
int cruising = 0;
float T = 1;

/*
* Funzione che prende in input un messaggio con le coordinate
* e setta un nuovo goal
*/

void SetGoal_Callback(const prog_pkg::Goal& new_goal){

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

    target_position[0] = new_goal_msg.pose.position.x;
    target_position[1] = new_goal_msg.pose.position.y;

}

void pickerCallback(const prog_pkg::Picker& picker)
{
    ROS_INFO("ricevo valore picker x di: [%f]",picker.x);
    ROS_INFO("ricevo valore picker y di: [%f]",picker.y);
    ROS_INFO("ricevo valore picker theta di: [%f]",picker.theta);
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

void check1_CallBack(const ros::TimerEvent& event)
{
    // eseguo il controllo solo se mi muovo

    if (cruising != 0)
    {
        ROS_INFO("Check if i'm moving");
        float distance;
        distance = sqrt(pow(current_position[0] - old_position[0],2) + pow(current_position[1] - old_position[1],2));

        /*
        * Se non mi sono spostato di una certa treshold  
        * allora comunico che mi sono bloccato
        */

        if (distance < 0.8)
        {
            ROS_INFO("I'm stuck!");
        }
        if (sqrt(pow(current_position[0] - target_position[0],2) + pow(current_position[1] - target_position[1],2)) < 1.5)
        {
            ROS_INFO("Arrived to the goal");
            cruising = 0;
        }
    }
    
}

void check2_CallBack(const ros::TimerEvent& event)
{
    // eseguo il controllo solo se mi muovo

    if (cruising != 0)
    {
        ROS_INFO("Checking if it has been passed too much time...");
        float distance;
        distance = sqrt(pow(current_position[0] - target_position[0],2) + pow(current_position[1] - target_position[1],2));

        if (distance > 0.5)
        {
            ROS_INFO("TIMEOUT: Goal point could not be reached!");
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
    
    ros::init(argc,argv,"set_goal");

    ros::NodeHandle n;
    ros::Publisher pub = n.advertise<geometry_msgs::PoseStamped>("/move_base_simple/goal",1000);

    tf2_ros::TransformListener tfListener(tfBuffer);

    ros::Rate loop_rate(T);

    // ros::Subscriber sub = n.subscribe("New_Goal",1000,SetGoal_Callback);
    // ros::Subscriber sub_tf = n.subscribe("tf",1000,position_CallBack);

    // ricevo le coordinate del picker
    ros::Subscriber sub_picker = n.subscribe("picker",1000,pickerCallback);

    /* Controllo con dei tempi prefissati lo stato della navigazione
    *  del robot
    */

    ros::Timer timer1 = n.createTimer(ros::Duration(0.5), check1_CallBack);
    ros::Timer timer2 = n.createTimer(ros::Duration(50), check2_CallBack);

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

        ros::spinOnce();

        loop_rate.sleep();

        ++count;
    }
    
    return 0;
}