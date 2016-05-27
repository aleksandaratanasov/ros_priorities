#ifndef MODE_H
#define MODE_H

class Mode
{
public:
Mode();
~Mode();
Mode& operator=(const Mode& other);
bool operator==(const Mode& other);
};

#endif // MODE_H
