#include <FL/Fl.H>
#include <FL/Fl_Window.H>

#ifndef __FLAT_WINDOW__
#define __FLAT_WINDOW__

class flat_window : public Fl_Window
{
public:
    flat_window(int x, int y, int w, int h, const char *label = 0);
};

#endif // __FLAT_WINDOW__
