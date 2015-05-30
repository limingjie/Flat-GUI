//
// flat_window.hpp
//
// May 30, 2015 - by Mingjie Li (limingjie@outlook.com)
// https://github.com/limingjie/libcsvmm
//
#ifndef __FLAT_WINDOW__
#define __FLAT_WINDOW__

#include <FL/Fl.H>
#include <FL/Fl_Window.H>

class flat_window : public Fl_Window
{
private:
    void draw();

public:
    flat_window(int x, int y, int w, int h, const char *label = 0);
};

#endif // __FLAT_WINDOW__
