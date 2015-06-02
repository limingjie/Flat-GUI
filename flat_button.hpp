//
// flat_button.hpp
//
// May 30, 2015 - by Mingjie Li (limingjie@outlook.com)
// https://github.com/limingjie
//
#ifndef __FLAT_BUTTON__
#define __FLAT_BUTTON__

#include <FL/Fl_Button.H>

class flat_button : public Fl_Button
{
private:
    int handle(int event);

public:
    void activate();
    void deactivate();
    flat_button(int x, int y, int w, int h, const char *label = 0);
};

#endif // __FLAT_BUTTON__
