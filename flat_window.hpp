#include <FL/Fl.H>
#include <FL/Fl_Window.H>

#include <string>

class flat_window : public Fl_Window
{
public:
    flat_window(int x, int y, int w, int h, const std::string &label = "");
};
