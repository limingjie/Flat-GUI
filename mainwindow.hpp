#include <FL/Fl.H>
#include <FL/Fl_Widget.H>
#include <FL/Fl_Window.H>
#include <FL/Fl_Tabs.H>
#include <FL/Fl_Group.H>
#include <FL/Fl_Box.H>
#include <FL/Fl_Input.H>
#include <FL/Fl_Text_Buffer.H>
#include <FL/Fl_Text_Display.H>
#include "flat_button.hpp"

class MainWindow : public Fl_Window
{
public:
    MainWindow(int w, int h, const char *label = 0);
    MainWindow(int x, int y, int w, int h, const char *label = 0);

    ~MainWindow();

private:
    void createUI();

private:  // UI Components
    Fl_Text_Buffer     *consoleBuffer;

    Fl_Input           *branchInput;
    flat_button        *branchButton;
    Fl_Text_Display    *memberTextbox;
    Fl_Text_Display    *consoleTextbox;

private:  // Callbacks
    static void onButtonClick_static(Fl_Widget *w, void *f);
    void onButtonClick(Fl_Widget *w);
};
