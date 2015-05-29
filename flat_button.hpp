#include <FL/Fl_Button.H>
#include <string>

class flat_button : public Fl_Button
{
private:
    int handle(int event);

public:
    flat_button(int x, int y, int w, int h, const std::string &label = "");
};
