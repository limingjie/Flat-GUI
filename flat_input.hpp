//
// flat_input.hpp
//
// May 30, 2015 - by Mingjie Li (limingjie@outlook.com)
// https://github.com/limingjie/libcsvmm
//
#ifndef __FLAT_INPUT__
#define __FLAT_INPUT__

#include <FL/Fl_Input.H>

class flat_input : public Fl_Input
{
private:
    int handle(int event);
    void draw();

public:
    void activate();
    void deactivate();
    flat_input(int x, int y, int w, int h, const char *label = 0);
};

#endif // __FLAT_INPUT__
