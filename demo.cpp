#include <FL/Fl.H>

#include "mainwindow.hpp"

int main(int argc, char **argv)
{
    MainWindow *window = new MainWindow(100, 100, 600, 300, "Foo bar");
    window->color(fl_rgb_color(80, 140, 220));
    window->clear_border();
    window->show(argc, argv);
    return Fl::run();
}
