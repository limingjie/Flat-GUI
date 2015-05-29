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
	$(CXX) $(CXXFLAGS) $(FLTK_CXXFLAGS) -c demo.cpp

mainwindow.o: mainwindow.cpp mainwindow.hpp flat_window.hpp flat_button.hpp
	$(CXX) $(CXXFLAGS) $(FLTK_CXXFLAGS) -c mainwindow.cpp

flat_button.o: flat_button.cpp flat_button.hpp
	$(CXX) $(CXXFLAGS) $(FLTK_CXXFLAGS) -c flat_button.cpp

flat_window.o: flat_window.cpp flat_window.hpp
	$(CXX) $(CXXFLAGS) $(FLTK_CXXFLAGS) -c flat_window.cpp

flatgui$(X): demo.o mainwindow.o flat_window.o flat_button.o
	$(CXX) -o flatgui$(X) demo.o mainwindow.o flat_window.o flat_button.o $(FLTK_LDSTATIC)

clean:
	rm -f *.o
	rm -f flatgui$(X)
