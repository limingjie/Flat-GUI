#include <FL/Fl_Button.H>

#ifndef __FLAT_BUTTON__
#define __FLAT_BUTTON__

class flat_button : public Fl_Button
{
private:
    int handle(int event);

public:
    flat_button(int x, int y, int w, int h, const char *label = 0);
};

#endif // __FLAT_BUTTON__
