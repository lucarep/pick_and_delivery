#include "ros/ros.h"
#include <vector>
#include "std_msgs/String.h"
#include "prog_pkg/Goal.h"
#include "geometry_msgs/PoseStamped.h"
#include "tf/tf.h"
#include "tf2_msgs/TFMessage.h"
#include <sstream>
#include "tf2_ros/transform_listener.h"
#include "geometry_msgs/TransformStamped.h"
#include "nav_msgs/Odometry.h"
#include "sensor_msgs/LaserScan.h"

std::vector<float> target_position(2,0);
std::vector<float> old_position(2,0);
std::vector<float> current_position(2,0);

geometry_msgs::PoseStamped new_goal_msg;
tf2_ros::Buffer tfBuffer;

size_t n = 10;
int message_published = 0;
int cruising = 0;
float T = 1;

void SetGoal_Callback(const prog_pkg::Goal& new_goal){

    new_goal_msg.header.seq = n;
    n++;

    new_goal_msg.header.stamp = ros::Time::now();
    new_goal_msg.header.frame_id = "map";

    new_goal_msg.pose.position.x = new_goal.x;
    new_goal_msg.pose.position.y = new_goal.y;
    new_goal_msg.pose.position.z = 0;

    new_goal_msg.pose.orientation.x = 0;
    new_goal_msg.pose.orientation.y = 0;
    new_goal_msg.pose.orientation.z = 0;
    new_goal_msg.pose.orientation.w = new_goal.theta;

    message_published = 1;
    cruising = 1;

    // Save the goal position
    target_position[0] = new_goal_msg.pose.position.x;
    target_position[1] = new_goal_msg.pose.position.y;

    // pub.publish(new_goal_msg);
}

void position_CallBack(const tf2_msgs::TFMessage& tf)
{
    int transform_ok;
    transform_ok = tfBuffer.canTransform("map", "base_link",ros::Time(0));

    if (transform_ok != 0)
    {
        geometry_msgs::TransformStamped transfromStamped;
        transfromStamped = tfBuffer.lookupTransform("map", "base_link", ros::Time(0));

        current_position[0] = transfromStamped.transform.translation.x;
        current_position[1] = transfromStamped.transform.translation.y;

    }
    
}

void check1_CallBack(const ros::TimerEvent& event)
{
    if (cruising != 0)
    {
        ROS_INFO("Check if i'm moving");
        float distance;
        distance = sqrt(pow(current_position[0] - old_position[0],2) + pow(current_position[1] - old_position[1],2));

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
    
    ros::init(argc,argv,"set_goal");

    ros::NodeHandle n;
    ros::Publisher pub = n.advertise<geometry_msgs::PoseStamped>("/move_base_simple/goal",1000);

    tf2_ros::TransformListener tfListener(tfBuffer);

    ros::Rate loop_rate(T);

    ros::Subscriber sub = n.subscribe("New_Goal",1000,SetGoal_Callback);
    ros::Subscriber sub_tf = n.subscribe("tf",1000,position_CallBack);

    ros::Timer timer1 = n.createTimer(ros::Duration(0.5), check1_CallBack);
    ros::Timer timer2 = n.createTimer(ros::Duration(50), check2_CallBack);

    int count = 0;
    while (ros::ok())
    {
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