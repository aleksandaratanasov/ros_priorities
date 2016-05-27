#include "../include/mode.h"

Mode::Mode()
  : priority(PRIORITY_LOWEST),
    finished(true),
    name("")
{

}

Mode::Mode(uint32_t _priority, std::string _name)
  : priority(_priority),
    finished(true),
    name(_name)
{
}

Mode::~Mode()
{

}

Mode& Mode::operator=(const Mode& other)
{
  name = other.name;
  priority = other.priority;
  finished = true;
}

bool Mode::operator==(const Mode& other)
{
  return this->priority == other.priority;
}

bool Mode::operator<(const Mode& other)
{
  return this->priority < other.priority;
}

bool Mode::operator>(const Mode& other)
{
  return this->priority > other.priority;
}

void Mode::setPriority(uint32_t _priority)
{
  priority = _priority;
}

uint32_t Mode::getPriority()
{
  return priority;
}

void Mode::setName(std::string _name)
{
  name = _name;
}

std::string Mode::getName()
{
  return name;
}

bool Mode::isFinished()
{
  return finished;
}

void Mode::start()
{

}

void Mode::pause()
{

}

void Mode::stop()
{

}


