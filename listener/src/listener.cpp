#include <iostream>
#include <ros/ros.h>
#include <std_msgs/String.h>

class ListenerNode {
    private: ros::NodeHandle nh;
    private: ros::Subscriber sub;

    public: ListenerNode() {
        sub = nh.subscribe("say_hello",10 ,&ListenerNode::subscriber_callback, this);
    }

    public: void subscriber_callback(const std_msgs::String::ConstPtr& msg) {
        ROS_INFO("I heard %s", msg->data.c_str());
    }
};


int main(int argc, char** argv) {
    ros::init(argc, argv, "listener_node");
    ListenerNode listener;
    ros::spin();
    return 0;
}