#include "flat_window.hpp"
#include "flat_common.hpp"

#include <FL/fl_draw.H>

flat_window::flat_window(int x, int y, int w, int h, const char *label)
    : Fl_Window(x, y, w, h, label)
{
    box(FL_FLAT_BOX);
    color(flat_white);
    clear_border();
}

void flat_window::draw()
{
    Fl_Window::draw();
    fl_rect(0, 0, w(), h(), flat_black);
}
