//g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images` -std=c++11
#include "Simple_window.h"
#include "Graph.h"

int main()
{
    using namespace Graph_lib;

    int xmax = 600;
    int ymax = 400;
    Simple_window win {Point{100,100}, xmax, ymax, "My window"};
    
	Axis xa {Axis::x, Point{50,250}, 200, 20, "x axis"};
	Axis ya {Axis::y, Point{50,250}, 200, 20, "y axis"};
	
	xa.set_color(Color::red);
	ya.set_color(Color::red);
	xa.label.set_color(Color::dark_red);
	ya.label.set_color(Color::dark_red);
	
	Function sine {sin,0,100,Point{50,150},1000,10,10};
	sine.set_color(Color::blue);
	
	Polygon haromsz;
	haromsz.add(Point{300,200});
	haromsz.add(Point{350,100});
	haromsz.add(Point{400,200});
	haromsz.set_color(Color::green);
	haromsz.set_style(Line_style::dot);
	
	Rectangle r {Point{50,250}, 200, 200};
	
	Closed_polyline poly_rect;
	poly_rect.add(Point{120,70}); 
	poly_rect.add(Point{200,40});
	poly_rect.add(Point{200,120});
	poly_rect.add(Point{100,200});
	poly_rect.add(Point{100,300});

	r.set_fill_color(Color::blue);
	haromsz.set_style(Line_style(Line_style::dash,4)); 
	poly_rect.set_style(Line_style(Line_style::dot,2));
	poly_rect.set_fill_color(Color::green);
	
	Text t {Point{100,100}, "Hello, graphical world!"};
	t.set_font(Font::times);
	t.set_font_size(30);
	
	Image im {Point{100,50},"kep.jpg"};
	
	Circle c {Point{100,200},50};
	Ellipse e {Point{100,200}, 75,25}; 
	e.set_color(Color::white);
	Mark m {Point{100,200},'x'};
	ostringstream oss;
	oss << "screen size: " << x_max() << "x" << y_max()
	<< "; window size: " << win.x_max() << "x" << win.y_max();
	Text sizes {Point{100,20},oss.str()};

	win.attach(c);
	win.attach(m);
	win.attach(e);
	win.attach(sizes);
	win.attach(im);
	win.attach(t);
	win.attach(poly_rect);
	win.attach(r);
	win.attach(xa);
	win.attach(ya);
	win.attach(sine);
	win.attach(haromsz);
	
    win.wait_for_button();
}
