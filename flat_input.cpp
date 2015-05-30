#include "flat_input.hpp"
#include "flat_common.hpp"

flat_input::flat_input(int x, int y, int w, int h, const char *label)
    : Fl_Input(x, y, w, h, label)
{
    // widget
    box(FL_FLAT_BOX);
    color(flat_white);

    // cursor
    cursor_color(flat_black);

    // text
    textsize(12);
    textcolor(flat_black);

    // selection
    selection_color(flat_blue);

    // label
    labelsize(12);
    labelcolor(flat_black);
}

void flat_input::activate()
{
    color(flat_white);
    Fl_Input::activate();
}

void flat_input::deactivate()
{
    color(flat_gray);
    Fl_Input::deactivate();
}

int flat_input::handle(int event)
{
    if (active())
    {
        switch (event)
        {
        case FL_ENTER:
            color(flat_lime);
            redraw();
            return 1;
        case FL_LEAVE:
            color(flat_white);
            redraw();
            return 0;
        }
    }

    return Fl_Input::handle(event);
}

void flat_input::draw()
{
    Fl_Input::draw();
    fl_rect(x(), y(), w(), h(), flat_gray);
}
