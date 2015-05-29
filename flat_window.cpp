#include "flat_window.hpp"

flat_window::flat_window(int x, int y, int w, int h, const std::string &label)
    : Fl_Window(x, y, w, h, label.c_str())
{
    color(fl_rgb_color(80, 140, 220));
    clear_border();
}
