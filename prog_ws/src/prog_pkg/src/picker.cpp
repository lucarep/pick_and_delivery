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

// Posizione per prendere il pacco

float picker_x;
float picker_y;
float picker_theta;

// Posizione per consegnare il pacco

float deliver_x;
float deliver_y;
float deliver_theta;

// Flag di controllo

int message_published = 0;
int info_published = 0;
int is_arrived = 0;
int loaded = 0;

void arrivedCallback(const prog_pkg::Arrived& arrived)
{
    ROS_INFO("Eccomi,sono arrivato da te e sono pronto per ricevere il pacco");
    is_arrived = arrived.reached_goal;
}

bool isLoaded(prog_pkg::IsLoaded::Request& req,prog_pkg::IsLoaded::Response& res)
{
    std::cout << ("Comunica al robot con (1) di aver caricato il pacco, altrimenti (0): ");
    std::cin >> loaded;
    res.result = loaded;
    ROS_INFO("Ok, comunico al robot la tua risposta: [%d]", res.result);
    return true;
}


int main(int argc, char **argv){

    std::cout << R"(
    ____  _      __            
   / __ \(_)____/ /_____  _____
  / /_/ / / ___/ //_/ _ \/ ___/
 / ____/ / /__/ ,< /  __/ /    
/_/   /_/\___/_/|_|\___/_/     
                               
)" << '\n';

    std::cout << ("Ciao, benvenuto nel servizio di pick and delivery del DIAG!") << '\n';
    std::cout << ("Per favore dimmi dove ti trovi . .. ...") << '\n';
    std::cout << ("x: ");
    std::cin >> picker_x;
    std::cout << ("y: ");
    std::cin >> picker_y;
    std::cout << ("theta: ");
    std::cin >> picker_theta;
    std::cout << ("Benissimo, adesso dimmi dove vuoi che consegni il tuo pacco . .. ...") << '\n';
    std::cout << ("x: ");
    std::cin >> deliver_x;
    std::cout << ("y: ");
    std::cin >> deliver_y;
    std::cout << ("theta: ");
    std::cin >> deliver_theta;
    std::cout << ("E' tutto ok, mi metto subito in viaggio verso di te per prendere il pacco") << '\n';

    ros::init(argc,argv,"picker");

    ros::NodeHandle n;

    ros::Publisher picker_pub = n.advertise<prog_pkg::Picker>("picker",1000);

    ros::Publisher deliver_pub = n.advertise<prog_pkg::Deliver>("deliver",1000);

    ros::Subscriber sub_arrived = n.subscribe("arrived",1000,arrivedCallback);

    ros::ServiceServer service = n.advertiseService("is_loaded",isLoaded);

    ros::Rate loop_rate(10);

    int count = 0;
    while (ros::ok())
    {
        /*
        * Invio 10 volte il goal per evitare problemi di perdita di dati
        * causati dal lag della socket
        */

        if(message_published < 10){

            prog_pkg::Picker picker;
            picker.x = picker_x;
            picker.y = picker_y;
            picker.theta = picker_theta;

            prog_pkg::Deliver deliver;
            deliver.x = deliver_x;
            deliver.y = deliver_y;
            deliver.theta = deliver_theta;

            if (info_published == 0)
            {
                ROS_INFO("pubblico valore picker x di: [%f]",picker.x);
                ROS_INFO("pubblico valore picker y di: [%f]",picker.y);
                ROS_INFO("pubblico valore picker theta di: [%f]",picker.theta);
                std::cout << ("----------------------------------------") << '\n';
                ROS_INFO("pubblico valore deliver x di: [%f]",deliver.x);
                ROS_INFO("pubblico valore deliver y di: [%f]",deliver.y);
                ROS_INFO("pubblico valore deliver theta di: [%f]",deliver.theta);
                
                info_published++;
            }
            
            picker_pub.publish(picker);
            deliver_pub.publish(deliver);
            message_published++;
        }
        
        ros::spinOnce();

        if (is_arrived == 1)
        {
            ROS_INFO("Pronto per comunicare al robot di aver caricato il pacco . .. ...");
            ros::spin();
        }
        
        
        loop_rate.sleep();
        ++count; 
    }
    
    return 0;
}