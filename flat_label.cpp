#include "flat_label.hpp"
#include "flat_common.hpp"

flat_label::flat_label(int x, int y, int w, int h, const char *label)
    : Fl_Box(x, y, w, h, label)
{
    align(FL_ALIGN_INSIDE | FL_ALIGN_LEFT);

    // label
    labelsize(12);
    labelcolor(flat_black);
}
