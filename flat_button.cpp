#include "flat_button.hpp"

flat_button::flat_button(int x, int y, int w, int h, std::string label)
    : Fl_Button(x, y, w, h, label.c_str())
{
    box(FL_FLAT_BOX);
    down_box(FL_FLAT_BOX);
    color(fl_rgb_color(60, 120, 220));
    down_color(fl_rgb_color(100, 160, 220));
    labelcolor(fl_rgb_color(255, 255, 255));
    clear_visible_focus();
}

int flat_button::handle(int event)
{
    switch (event)
    {
    case FL_ENTER:
        color(fl_rgb_color(80, 140, 220));
        redraw();
        return 1;
    case FL_LEAVE:
        color(fl_rgb_color(60, 120, 220));
        redraw();
        return 0;
    default:
        return Fl_Button::handle(event);
    }
}
