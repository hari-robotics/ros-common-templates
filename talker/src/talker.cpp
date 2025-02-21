#include <ros/ros.h>
#include <std_msgs/String.h>
#include <iostream>
#include "sample_msgs/Point.h"

class TalkerNode {
    private: ros::NodeHandle nh;
    private: ros::Publisher std_pub;
    private: ros::Publisher smp_pub;

    public: TalkerNode() {
        std_pub = nh.advertise<std_msgs::String>("say_hello", 10);
        smp_pub = nh.advertise<sample_msgs::Point>("msg_test", 10);
    }

    public: void publish(std_msgs::String &msg, sample_msgs::Point &points) {
        std_pub.publish(msg);
        smp_pub.publish(points);
    }

    public: void subscriber_callback(const std_msgs::String::ConstPtr& msg) {
        ROS_INFO("I heard %s", msg->data.c_str());
    }
};

int main(int argc, char **argv) {
    ros::init(argc, argv, "talker_node");
    TalkerNode talker;
    ros::Rate rate(1);

    std_msgs::String msg;
    sample_msgs::Point point;
    msg.data = "Hello World";
    point.x = 1;

    while (ros::ok()) {
        talker.publish(msg, point);
        ros::spinOnce();
        rate.sleep();
    }
    return 0;
}