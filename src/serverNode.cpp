#include "serverNode.h"

ServerNode::ServerNode()
{
}

ServerNode::~ServerNode()
{
}

void ServerNode::subscriberCallback(const prio_playground::Chatter::ConstPtr &subMsg)
{
  // React upon receiving a message from client
  ROS_INFO("received %s", subMsg->message.c_str());
}
