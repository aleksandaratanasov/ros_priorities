#include "serverNode.h"
//#include "prio_playground/serverNode.h"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "prio_server");
  ros::NodeHandle nh;
  int rate;
  nh.param("rate", rate, int(40));

  ServerNode *server = new ServerNode();

  ros::Subscriber sub_message = nh.subscribe("example", 1000, &ServerNode::subscriberCallback, server);

  ros::Rate r(rate);

  while (nh.ok())
  {
    ros::spinOnce();
    r.sleep();
  }

  return 0;
}
