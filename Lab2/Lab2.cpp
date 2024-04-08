#include "Figure.h"
#include "Figure_manager.h"

#include <iostream>

int main()
{
	Circle circle(5);

	circle.calculate_area();

	cout << "circle.calculate_area();" << circle.get_area() << endl;

	Rectangle rec(10, 5);

	rec.calculate_area();

	cout << "circle.calculate_area();" << circle.get_area() << endl;

	cout << "rec.calculate_area();" << rec.get_area() << endl;


}