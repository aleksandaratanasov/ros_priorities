//#include "clientNode.h"
#include "clientNode.h"

int main(int argc, char **argv)
{
ros::init(argc, argv, "prio_client");
  ros::NodeHandle nh;

  ClientNode *client = new ClientNode();
  ros::Publisher pub = nh.advertise<prio_playground::Chatter>("example", 10);
  ros::Rate r(40);
  std::string msg = "Hello!";

  while (nh.ok())
  {
    client->publisherCallback(&pub, msg); // publisherCallback(&pub, msg);

    ros::spinOnce();
    r.sleep();
  }

  return 0;
}
