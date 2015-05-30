//
// mainwindow.hpp
//
// May 30, 2015 - by Mingjie Li (limingjie@outlook.com)
// https://github.com/limingjie/libcsvmm
//
#ifndef __MAIN_WINDOW__
#define __MAIN_WINDOW__

#include <FL/Fl.H>
#include <FL/Fl_Text_Buffer.H>
#include <FL/Fl_Text_Display.H>

#include "flat_window.hpp"
#include "flat_button.hpp"
#include "flat_input.hpp"

class MainWindow : public flat_window
{
private:  // UI Components
    Fl_Text_Buffer     *consoleBuffer;

    flat_input         *branchInput;
    flat_button        *branchButton;
    Fl_Text_Display    *memberTextbox;
    Fl_Text_Display    *consoleTextbox;

private:  // Callbacks
    static void onButtonClick(Fl_Widget *sender, MainWindow *obj);

private:
    void createUI();

public:
    MainWindow(int x, int y, int w, int h, const char *label = 0);
    ~MainWindow();
};

#endif //__MAIN_WINDOW__
