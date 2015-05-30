#include <FL/Fl.H>

#include "window.hpp"

int main(int argc, char **argv)
{
    MainWindow *window = new MainWindow(100, 100, 600, 300, "Foo bar");
    window->show(argc, argv);
    return Fl::run();
}
