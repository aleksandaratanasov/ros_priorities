#ifndef CLIENTNODE_H
#define CLIENTNODE_H

#include<ros/ros.h>
#include<ros/time.h>
#include<string>

#include <prio_playground/Chatter.h>

class ClientNode
{
public:
  ClientNode();
  ~ClientNode();
  
  void publisherCallback(ros::Publisher *pub, std::string msg);
};

#endif // CLIENTNODE_H
