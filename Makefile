# Check OS
uname_S := $(shell sh -c 'uname -s 2>/dev/null || echo not')

ifneq (,$(findstring MINGW,$(uname_S)))
	X=.exe
endif

ifeq ($(OS),Windows_NT)
	X=.exe
endif

# Check CXX flag.
ifeq ($(CXX),clang++)
	CXX=clang++
else
	CXX=g++
endif

FLTK_CXXFLAGS  = $(shell fltk-config --cxxflags)
FLTK_LDSTATIC  = $(shell fltk-config --ldstaticflags)
CXXFLAGS       = -Wall -g -O2 -std=c++0x

all: flatgui$(X)

demo.o: demo.cpp mainwindow.hpp
	$(CXX) -c $(CXXFLAGS) $(FLTK_CXXFLAGS) -o demo.o demo.cpp

mainwindow.o: mainwindow.cpp mainwindow.hpp flat_window.hpp flat_button.hpp
	$(CXX) -c $(CXXFLAGS) $(FLTK_CXXFLAGS) -o mainwindow.o mainwindow.cpp

flat_label.o: flat_label.cpp flat_label.hpp flat_colors.hpp
	$(CXX) -c $(CXXFLAGS) $(FLTK_CXXFLAGS) -o flat_label.o flat_label.cpp

flat_button.o: flat_button.cpp flat_button.hpp flat_colors.hpp
	$(CXX) -c $(CXXFLAGS) $(FLTK_CXXFLAGS) -o flat_button.o flat_button.cpp

flat_window.o: flat_window.cpp flat_window.hpp flat_colors.hpp
	$(CXX) -c $(CXXFLAGS) $(FLTK_CXXFLAGS) -o flat_window.o flat_window.cpp

flatgui$(X): demo.o mainwindow.o flat_window.o flat_button.o flat_label.o
	$(CXX) -o flatgui$(X) demo.o mainwindow.o flat_window.o flat_button.o flat_label.o $(FLTK_LDSTATIC)

clean:
	rm -f *.o
	rm -f flatgui$(X)
