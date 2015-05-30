//
// flat_label.hpp
//
// May 30, 2015 - by Mingjie Li (limingjie@outlook.com)
// https://github.com/limingjie/libcsvmm
//
#ifndef __FLAT_LABEL__
#define __FLAT_LABEL__

#include <FL/Fl_Box.H>

class flat_label : public Fl_Box
{
public:
    flat_label(int x, int y, int w, int h, const char *label = 0);
};

#endif // __FLAT_LABEL__
