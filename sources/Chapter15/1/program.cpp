//g++ program.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o program `fltk-config --ldflags --use-images` -std=c++11
#include "Simple_window.h"
#include "Graph.h"

int main()
{
    using namespace Graph_lib;

    int xmax = 600;
    int ymax = 600;
    Simple_window win {Point{100,100}, xmax, ymax, "Function graphs"};
    Axis x {Axis::x,Point{100,300}, 400, 20, "1 == 20 pixels"};
    Axis y {Axis::y,Point{300,500}, 400, 20, "1 == 20 pixels"};
    x.set_color(Color::red);
    y.set_color(Color::red);
    win.attach(x);
    win.attach(y);
	win.wait_for_button();
}
