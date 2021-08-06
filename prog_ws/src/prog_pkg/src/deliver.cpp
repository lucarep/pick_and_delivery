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

int is_delivered = 0;
int picked = 0;

void deliveredCallback(const prog_pkg::Arrived& delivered){
    ROS_INFO("Eccomi sono arrivato da te e pronto per consegnare il pacco");
    is_delivered = delivered.reached_goal;

}

bool isPickedUp(prog_pkg::IsLoaded::Request& req,prog_pkg::IsLoaded::Response& res)
{
    std::cout << ("Comunica al robot con (1) di aver ritirato il pacco, altrimenti (0): ");
    std::cin >> picked;
    res.result = picked;
    ROS_INFO("Ok, comunico al robot la tua risposta: [%d]", res.result);
    return true;
}
                                  

int main(int argc, char **argv){

    std::cout << R"(
    ____       ___                
   / __ \___  / (_)   _____  _____
  / / / / _ \/ / / | / / _ \/ ___/
 / /_/ /  __/ / /| |/ /  __/ /    
/_____/\___/_/_/ |___/\___/_/    )" << ('\n');


    std::cout << ('\n');

    std::cout << ("Ciao, benvenuto nel servizio di pick and delivery del DIAG") << ('\n');
    std::cout << ("Riceverai una notifica quando il robot sarà da te per consegnare il pacco ") << ('\n');

    ros::init(argc,argv,"deliver");

    ros::NodeHandle n;

    ros::Subscriber sub_delivered = n.subscribe("delivered",1000,deliveredCallback);

    ros::ServiceServer service = n.advertiseService("is_picked_up",isPickedUp);

    ros::Rate loop_rate(10);

    int count = 0;
    while(ros::ok())
    {
        if (is_delivered == 1)
        {
            // ROS_INFO("Ok, ora comunicami quando hai ritirato il pacco");
            is_delivered = 0;
        }
        
        loop_rate.sleep();
        ros::spinOnce();
        ++count;
    }

    return 0;
}