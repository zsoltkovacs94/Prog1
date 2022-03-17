//g++ program.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o program `fltk-config --ldflags --use-images` -std=c++11
#include "Simple_window.h"
#include "Graph.h"

double one(double x){ return 1;}
double slope(double x){ return x/2;}
double square(double x){ return x*x;}
double sloping_cos(double x){ return cos(x)+slope(x);}

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
    Function s1 {one, -10, 11, Point(300,300), 400, 20, 20};
    Function s2 {slope, -10, 11, Point(300,300), 400, 20, 20};
    Text s2label {Point{120,360},"x/2"};
    Function s3 {square, -10, 11, Point(300,300), 400, 20, 20};
    Function s4 {cos, -10, 11, Point(300,300), 400, 20, 20};
    s4.set_color(Color::blue);
    Function s5 {sloping_cos, -10, 11, Point(300,300), 400, 20, 20};
    win.attach(x);
    win.attach(y);
    win.attach(s1);
    win.attach(s2);
    win.attach(s2label);
    win.attach(s3);
    win.attach(s4);
    win.attach(s5);
	win.wait_for_button();
}
