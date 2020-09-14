#include "ros/ros.h"
#include "geometry_msgs/Twist.h"

class SpeedProfileNode
{
public:
  SpeedProfileNode()
  {
    speedPublisher = nh_.advertise<geometry_msgs::Twist>("/speed_profile/speed", 1);
  }

  void execute()
  {
    ros::Rate r(1);

    geometry_msgs::Twist twist;

    twist.linear.x = 4;

    while (ros::ok())
    {
      speedPublisher.publish(twist);
      ros::spinOnce();
      r.sleep();
    }
  }

private:
  ros::NodeHandle nh_;
  ros::Publisher speedPublisher;
};

int main(int argc, char **argv)
{
  ros::init(argc, argv, "speed_profile");
  SpeedProfileNode node{};
  node.execute();
  return 0;
}
