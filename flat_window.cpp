#include "flat_window.hpp"
#include "flat_colors.hpp"

flat_window::flat_window(int x, int y, int w, int h, const char *label)
    : Fl_Window(x, y, w, h, label)
{
    color(flat_gray);
    //clear_border();
}
