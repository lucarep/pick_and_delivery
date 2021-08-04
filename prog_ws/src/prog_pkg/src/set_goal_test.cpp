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
     
}

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

int main(int argc, char **argv){

    ros::init(argc,argv,"set_goal_test");

    ros::NodeHandle n;

    ros::Subscriber sub_picker = n.subscribe("picker",1000,pickerCallback);

    ros::Subscriber sub_deliver = n.subscribe("deliver",1000,deliverCallback);

    ros::spin();

    return 0;

}