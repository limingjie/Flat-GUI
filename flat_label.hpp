#include <FL/Fl_Box.H>

#ifndef __FLAT_LABEL__
#define __FLAT_LABEL__

class flat_label : public Fl_Box
{
public:
    flat_label(int x, int y, int w, int h, const char *label = 0);
};

#endif // __FLAT_LABEL__
