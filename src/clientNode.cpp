#include "clientNode.h"

ClientNode::ClientNode()
{
}

ClientNode::~ClientNode()
{
}

void ClientNode::publisherCallback(ros::Publisher *pub, std::string msg)
{
  // Send message to server
  prio_playground::Chatter cMsg;
  cMsg.message = msg;
  ROS_INFO("sent %s", cMsg.message.c_str());
  
  pub->publish(cMsg);
}
