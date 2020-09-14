#include "ros/ros.h"
#include "geometry_msgs/Twist.h"
#include "geometry_msgs/Pose.h"

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
      //update callbacks
      ros::spinOnce();

      speedPublisher.publish(twist);

      //Check value of rosparam
      ROS_INFO_STREAM("Kp: " << Kp_);

      //Break node
      const auto den = generateDen();
      const auto sum = static_cast<int>(42 / den);
      ROS_INFO_STREAM("sum: " << sum);
      int arr[10];
      ROS_INFO_STREAM("value at index: " << arr[sum]);

      //Sleep for rest of duration
      r.sleep();
    }
  }

private:
  ros::NodeHandle nh_{};
  ros::NodeHandle pnh_{"~"};
  ros::Publisher speedPublisher;

  const double Kp_ =
      pnh_.param("Kp", 1.0);

  float generateDen()
  {
    float den = 3.14;
    return den;
  }
};

int main(int argc, char **argv)
{
  ros::init(argc, argv, "speed_profile");
  SpeedProfileNode node{};
  node.execute();
  return 0;
}
