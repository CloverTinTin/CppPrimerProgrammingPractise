#ifndef SCREEN_H
#define SCREEN_H

#include <iostream>
#include <string>

class Screen
{
public:
    using pos = std::string::size_type;
    Screen() = default;
    Screen(pos ht, pos wd, char c): height(ht), width(wd), contents(ht * wd, c){ }
    inline char get() const{return contents[cursor];}
    char get(pos x, pos y) const;
    Screen &move(pos x, pos y);

private:
    pos          cursor = 0;
    pos          height = 0;
    pos          width = 0;
    std::string  contents;
};

char Screen::get(pos x, pos y) const
{
    return contents[y * width + x];
}

inline Screen &Screen::move(pos x, pos y)
{
    cursor = y * width + x;
    return *this;
}

#endif
