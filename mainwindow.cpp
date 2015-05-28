#include "mainwindow.hpp"

#include <string>

MainWindow::MainWindow(int w, int h, const char *label)
    : Fl_Window(w, h, label)
{
    createUI();
}

MainWindow::MainWindow(int x, int y, int w, int h, const char *label)
    : Fl_Window(x, y, w, h, label)
{
    createUI();
}

MainWindow::~MainWindow()
{
    if (consoleBuffer)
    {
        delete consoleBuffer;
        consoleBuffer = NULL;
    }
}

void MainWindow::createUI()
{
    consoleBuffer = new Fl_Text_Buffer();

    Fl_Box *label = new Fl_Box(10, 35, 60, 25, "Branch");
    label->align(FL_ALIGN_INSIDE | FL_ALIGN_LEFT);

    branchInput = new Fl_Input(80, 35, 420, 25);

    branchButton = new flat_button(510, 35, 80, 25, "Search");
    branchButton->shortcut(FL_Enter);
    branchButton->callback(onButtonClick_static, (void *)this);

    label = new Fl_Box(10, 70, 60, 25, "Members");
    label->align(FL_ALIGN_INSIDE | FL_ALIGN_LEFT);

    memberTextbox = new Fl_Text_Display(80, 70, 510, 220);
    memberTextbox->buffer(consoleBuffer);

    this->resizable(memberTextbox);
}

void MainWindow::onButtonClick_static(Fl_Widget *w, void *f)
{
    ((MainWindow *)f)->onButtonClick(w);
}

void MainWindow::onButtonClick(Fl_Widget *w)
{
    consoleBuffer->append("clicked\n");
}
