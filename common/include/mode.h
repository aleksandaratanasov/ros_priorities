#ifndef MODE_H
#define MODE_H
//#include <boost/concept_check.hpp>
#include <boost/signals2.hpp>
#include <boost/thread.hpp>
#include <string>

#define PRIORITY_LOWEST 0
#define PRIORITY_HIGHEST 10

// TODO Add timeout support like in CoB's Mode. The timeout is used to disposed of modes that have taken longer then specified
class Mode
{
protected:
  uint32_t priority;
  bool finished;
  std::string name;
public:
  Mode();
  Mode(uint32_t priority, std::string name);
  ~Mode();
  Mode& operator=(const Mode& other);
  bool operator==(const Mode& other);
  bool operator<(const Mode& other);
  bool operator>(const Mode& other);
  
  void setPriority(uint32_t priority);
  uint32_t getPriority();
  
  void setName(std::string name);
  std::string getName();
  
  bool isFinished();
  
  void start();
  void pause();
  void stop();
  
  virtual void execute() = 0;
};

#endif // MODE_H
