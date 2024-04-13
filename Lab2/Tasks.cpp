#include "Figure.h"
#include "Figure_manager.h"
#include "Input.h"

#include <iostream>

using namespace std;

void add_circle(Figures_manager &figures){

	double radius = InputDouble("Enter circle's radius:", 0, DBL_MAX);

	figures.add_figure(make_shared<Circle>(radius));

}

void add_rectangle(Figures_manager &figures) {

	double length = InputDouble("Enter rectangle's length:", 0, DBL_MAX);
	double width = InputDouble("Enter rectangle's width:", 0, DBL_MAX);

	figures.add_figure(make_shared<Rectangle>(length, width));

}

void add_trapezoid(Figures_manager &figures) {

	double rigth_side = InputDouble("Enter trapezoid's rigth side:", 0, DBL_MAX);
	double left_side = InputDouble("Enter trapezoid's left side:", 0, DBL_MAX);
	double top_base = InputDouble("Enter trapezoid's top base:", 0, DBL_MAX);
	double bottom_base = InputDouble("Enter trapezoid's bottom base:", 0, DBL_MAX);
	double height = InputDouble("Enter trapezoid's height:", 0, DBL_MAX);

	figures.add_figure(make_shared<Trapezoid>(rigth_side, left_side, top_base, bottom_base, height));

}