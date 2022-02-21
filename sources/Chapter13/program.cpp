//g++ main.cpp Graph.cpp Window.cpp GUI.cpp Simple_window.cpp -o main `fltk-config --ldflags --use-images` -std=c++11
#include "Simple_window.h"
#include "Graph.h"

int main()
{
    using namespace Graph_lib;

    int xmax = 800;
    int ymax = 1000;
    Simple_window win {Point{100,100}, xmax, ymax, "Grid"};
    
    Lines grid;
	for (int x=0; x<=800; x+=100)
	grid.add(Point{x,0},Point{x,800});
	for (int y=0; y<=800; y+=100)
	grid.add(Point{0,y},Point{800,y});
    
    Vector_ref<Rectangle> vr;
	for (int i = 0; i<800; i+=100){
		vr.push_back(new Rectangle{Point{i,i},100,100});
		vr[i/100].set_fill_color(Color::red);
		win.attach(vr[i/100]);
	}
    
	Image im1 {Point{200,0},"kep.jpeg"};
	Image im2 {Point{0,200},"kep.jpeg"};
	Image im3 {Point{400,100},"kep.jpeg"};
	Image iM {Point{0,0},"kep2.jpeg"};
    
    win.attach(grid);
    win.attach(im1);
    win.attach(im2);
    win.attach(im3);
    win.attach(iM);
    for (int i = 0; i < 800; i+=100)
	{
		for (int j = 0; j < 800; j+=100)
		{
			win.wait_for_button();
			iM.move(100,0);
		}
		iM.move(-800,100);
	}
}
