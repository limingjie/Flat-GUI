#include "flat_button.hpp"
#include "flat_common.hpp"

flat_button::flat_button(int x, int y, int w, int h, const char *label)
    : Fl_Button(x, y, w, h, label)
{
    // box style & color
    box(FL_FLAT_BOX);
    down_box(FL_FLAT_BOX);
    color(flat_blue);
    down_color(flat_dark_blue);

    // label
    labelsize(12);
    labelcolor(flat_white);

    // tab focus
    clear_visible_focus();
}

void flat_button::activate()
{
    color(flat_blue);
    Fl_Button::activate();
}

void flat_button::deactivate()
{
    color(flat_gray);
    Fl_Button::deactivate();
}

int flat_button::handle(int event)
{
    if (active())
    {
        switch (event)
        {
        case FL_ENTER:
            color(flat_light_blue);
            redraw();
            return 1;
        case FL_LEAVE:
            color(flat_blue);
            redraw();
            return 0;
        }
    }

    return Fl_Button::handle(event);
}
