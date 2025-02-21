#include <iostream>
#include <ros/ros.h>
#include <std_msgs/String.h>
#include "sample_msgs/Point.h"

class ListenerNode {
    private: ros::NodeHandle nh;
    private: ros::Subscriber std_sub;
    private: ros::Subscriber smp_sub;

    public: ListenerNode() {
        std_sub = nh.subscribe("say_hello", 10, &ListenerNode::std_subscriber_callback, this);
        smp_sub = nh.subscribe("msg_test", 10, &ListenerNode::smp_subscriber_callback, this);
    }

    public: void std_subscriber_callback(const std_msgs::StringConstPtr& msg) {
        ROS_INFO("[Std Msg]: %s", msg->data.c_str());
    }

    public: void smp_subscriber_callback(const sample_msgs::PointConstPtr& msg) {
        ROS_INFO("[Got Point]: x:%f y:%f z:%f", msg->x, msg->y, msg->z);
    }
};


int main(int argc, char** argv) {
    ros::init(argc, argv, "listener_node");
    ListenerNode listener;
    ros::spin();
    return 0;
}