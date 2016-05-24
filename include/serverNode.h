#ifndef SERVERNODE_H
#define SERVERNODE_H

#include<ros/ros.h>
#include<ros/time.h>

#include <prio_playground/Chatter.h>

class ServerNode
{
public:
  ServerNode();
  ~ServerNode();
  
  void subscriberCallback(const prio_playground::Chatter::ConstPtr &subMsg);
};

#endif // SERVERNODE_H
