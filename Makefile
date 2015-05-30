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

demo.o: demo.cpp window.hpp
	$(CXX) -c $(CXXFLAGS) $(FLTK_CXXFLAGS) -o demo.o demo.cpp

window.o: window.cpp window.hpp flat_window.hpp flat_button.hpp
	$(CXX) -c $(CXXFLAGS) $(FLTK_CXXFLAGS) -o window.o window.cpp

flat_input.o: flat_input.cpp flat_input.hpp flat_common.hpp
	$(CXX) -c $(CXXFLAGS) $(FLTK_CXXFLAGS) -o flat_input.o flat_input.cpp

flat_label.o: flat_label.cpp flat_label.hpp flat_common.hpp
	$(CXX) -c $(CXXFLAGS) $(FLTK_CXXFLAGS) -o flat_label.o flat_label.cpp

flat_button.o: flat_button.cpp flat_button.hpp flat_common.hpp
	$(CXX) -c $(CXXFLAGS) $(FLTK_CXXFLAGS) -o flat_button.o flat_button.cpp

flat_window.o: flat_window.cpp flat_window.hpp flat_common.hpp
	$(CXX) -c $(CXXFLAGS) $(FLTK_CXXFLAGS) -o flat_window.o flat_window.cpp

flatgui$(X): demo.o window.o flat_window.o flat_button.o flat_label.o flat_input.o
	$(CXX) -o flatgui$(X) demo.o window.o flat_window.o flat_button.o flat_label.o flat_input.o $(FLTK_LDSTATIC)

clean:
	rm -f *.o
	rm -f flatgui$(X)
