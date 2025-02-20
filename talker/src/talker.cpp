#include <ros/ros.h>
#include <std_msgs/String.h>
#include <iostream>

class TalkerNode {
    private: ros::NodeHandle nh;
    private: ros::Publisher pub;

    public: TalkerNode() {
        pub = nh.advertise<std_msgs::String>("say_hello", 10);
    }

    public: void publish(std_msgs::String &msg) {
        pub.publish(msg);
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
    msg.data = "Hello World";

    while (ros::ok()) {
        talker.publish(msg);
        ros::spinOnce();
        rate.sleep();
    }
    return 0;
}