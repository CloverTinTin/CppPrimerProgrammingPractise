#ifndef CLASS_XY_H
#define CLASS_XY_H

class Y;

class X
{
    Y *yPtr = nullptr;
};

class Y
{
    X xObject; 
};

#endif
