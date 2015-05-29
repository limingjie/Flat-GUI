#include "mainwindow.hpp"
#include "flat_label.hpp"
#include "flat_button.hpp"

#define connect(widget, method) \
   widget->callback(reinterpret_cast<void(*)(Fl_Widget*, void*)>(method), this)

MainWindow::MainWindow(int x, int y, int w, int h, const char *label)
    : flat_window(x, y, w, h, label)
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

    flat_label *label = new flat_label(10, 35, 60, 25, "Branch");

    branchInput = new Fl_Input(80, 35, 420, 25);

    branchButton = new flat_button(510, 35, 80, 25, "Search");
    branchButton->shortcut(FL_Enter);
    connect(branchButton, onButtonClick);

    flat_label *label1 = new flat_label(10, 70, 60, 25, "Members");

    memberTextbox = new Fl_Text_Display(80, 70, 510, 220);
    memberTextbox->buffer(consoleBuffer);

    this->resizable(memberTextbox);
}

void MainWindow::onButtonClick(Fl_Widget *sender, MainWindow *obj)
{
    obj->consoleBuffer->append("clicked\n");
}
