#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

class LateralControlNode
{
public:
    LateralControlNode()
    {
        speedSubscriber = nh_.subscribe<geometry_msgs::Twist>(
            "/speed_profile/speed", 1, &LateralControlNode::speedCB, this);
    }

private:
    ros::NodeHandle nh_;

    ros::Subscriber speedSubscriber;
    geometry_msgs::Twist currentTwist_;
    void speedCB(const geometry_msgs::Twist::ConstPtr &msg)
    {
        currentTwist_ = *msg;
        ROS_INFO_STREAM("Hastigheten er: " << currentTwist_);
    }
};

int main(int argc, char **argv)
{
    ros::init(argc, argv, "lateral_control");
    LateralControlNode node{};
    ros::spin();
    return 0;
}
