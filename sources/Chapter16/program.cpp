//g++ program.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o program `fltk-config --ldflags --use-images` -std=c++11
#include "GUI.h"
using namespace Graph_lib;

struct Lines_window : Window {
	Lines_window(Point xy, int w, int h, const string& title);
	private:
	Open_polyline lines;
	Button next_button; 
	Button quit_button;
	In_box next_x;
	In_box next_y;
	Out_box xy_out;
	Menu color_menu;
	Button cmenu_button;
	Menu style_menu;
	Button smenu_button;
	void cchange(Color c) { lines.set_color(c); } 
	void hide_cmenu() { color_menu.hide(); cmenu_button.show(); }
	void red_pressed() { cchange(Color::red); hide_cmenu(); }
	void blue_pressed() { cchange(Color::blue); hide_cmenu(); } 
	void black_pressed() { cchange(Color::black); hide_cmenu(); } 
	void cmenu_pressed() { cmenu_button.hide(); color_menu.show(); }
	void schange(Line_style s) {lines.set_style(s);}
	void hide_smenu() { style_menu.hide();smenu_button.show();}
	void dotted_pressed() {schange(Line_style::dot); hide_smenu();}
	void dash_pressed() {schange(Line_style::dash); hide_smenu();}
	void solid_pressed() {schange(Line_style::solid); hide_smenu();}
	void smenu_pressed() { smenu_button.hide(); style_menu.show();}
	void next(); 
	void quit();
};

Lines_window::Lines_window(Point xy, int w, int h, const string& title)
	:Window{xy,w,h,title},
	next_button{Point{x_max()-150,0}, 70, 20, "Next point",
		[](Address, Address pw) {reference_to<Lines_window>(pw).next();}},
	quit_button{Point{x_max()-70,0}, 70, 20, "Quit",
		[](Address, Address pw) {reference_to<Lines_window>(pw).quit();}},
	next_x{Point{x_max()-310,0}, 50, 20, "next x:"},
	next_y{Point{x_max()-210,0}, 50, 20, "next y:"},
	xy_out{Point{100,0}, 100, 20, "current (x,y):"},
	color_menu{Point{x_max()-70,30},70,20,Menu::vertical,"color"},
	cmenu_button{Point{x_max()-80,30}, 80, 20, "color menu",
		[](Address, Address pw) {reference_to<Lines_window>(pw).cmenu_pressed();}},
	style_menu{Point{x_max()-140,30},70,20,Menu::vertical,"style"},
	smenu_button{Point{x_max()-160,30}, 80, 20, "style menu",
		[](Address, Address pw) {reference_to<Lines_window>(pw).smenu_pressed();}}
{
	attach(next_button);
	attach(quit_button);
	attach(next_x);
	attach(next_y);
	attach(xy_out);
	attach(lines);
	
	color_menu.attach(new Button{Point{0,0},0,0,"red",
		[](Address, Address pw) {reference_to<Lines_window>(pw).red_pressed();}});
	color_menu.attach(new Button{Point{0,0},0,0,"blue",
		[](Address, Address pw) {reference_to<Lines_window>(pw).blue_pressed();}});
	color_menu.attach(new Button{Point{0,0},0,0,"black",
		[](Address, Address pw) {reference_to<Lines_window>(pw).black_pressed();}});
	attach(color_menu);
	color_menu.hide();
	attach(cmenu_button);
 
	style_menu.attach(new Button{Point{0,0},0,0,"dotted",
		[](Address, Address pw) {reference_to<Lines_window>(pw).dotted_pressed();}});
	style_menu.attach(new Button{Point{0,0},0,0,"dash",
		[](Address, Address pw) {reference_to<Lines_window>(pw).dash_pressed();}});
	style_menu.attach(new Button{Point{0,0},0,0,"solid",
		[](Address, Address pw) {reference_to<Lines_window>(pw).solid_pressed();}});
	attach(style_menu);
	style_menu.hide();
	attach(smenu_button);
	attach(lines);
}
void Lines_window::quit()
{
	hide();
}

void Lines_window::next()
{
	int x = next_x.get_int();
	int y = next_y.get_int();
	lines.add(Point{x,y});
	ostringstream ss;
	ss << '(' << x << ',' << y << ')';
	xy_out.put(ss.str());
	redraw();
}

int main()
try {
	Lines_window win {Point{100,100},600,400,"lines"};
	return gui_main();
}
catch(exception& e) {
	cerr << "exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Some exception\n";
	return 2;
}

