#pragma once

#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>

using namespace std;

class Figure
{
protected:

	double area;
	double perimeter;

public:

	virtual void calculate_area() = 0;
	virtual void calculate_perimeter() = 0;

	virtual double get_area() = 0;
	virtual double get_perimeter() = 0;

	virtual void show_figure() = 0;

};

class Circle :public Figure
{

private:

	double radius;

public:

	Circle(double radius) : radius(radius) {}

	void calculate_area() override { area = radius * radius * M_PI; }
	void calculate_perimeter() override { perimeter = 2 * M_PI * radius; }

	double get_area() override { return area; }
	double get_perimeter() override { return  perimeter; }

	void show_figure() override {

		cout << "This is a figure circle:" << endl;
		cout << "Radius =" << radius << endl;
		cout << "Area =" << area << endl;
		cout << "Perimeter =" << perimeter << endl;

	}


};

class Rectangle :public Figure
{

private:

	double length;
	double width;

public:

	Rectangle(double length, double width) : length(length), width(width) {}

	void calculate_area() override { area = length * width; }
	void calculate_perimeter() override { perimeter = 2 * (length + width); }



	double get_area() override { return area; }
	double get_perimeter() override { return perimeter; }

	void show_figure() override {

		cout << "This is a figure rectangle:" << endl;
		cout << "Length =" << length << endl;
		cout << "Width =" << width << endl;
		cout << "Area =" << area << endl;
		cout << "Perimeter =" << perimeter << endl;

	}
};

class Trapezoid :public Figure
{

private:

	double right_side;
	double left_side;
	double top_base;
	double bottom_base;
	double height;

public:

	Trapezoid(double right_side, double left_side, double top_base, double bottom_base, double height) :
		right_side(right_side), left_side(left_side), top_base(top_base), bottom_base(bottom_base), height(height) {}


	void calculate_area() override { area = height* (top_base + bottom_base) / 2; }
	void calculate_perimeter() override { perimeter = right_side + left_side + top_base + bottom_base; }

	double get_area() override { return height * (top_base + bottom_base) / 2; }
	double get_perimeter() override { return right_side + left_side + top_base + bottom_base; }

	void show_figure() override {

		cout << "This is a figure trapezoid:" << endl;
		cout << "Right side =" << right_side << endl;
		cout << "Left side =" << left_side << endl;
		cout << "Top base =" << top_base << endl;
		cout << "Bottom base =" << bottom_base << endl;
		cout << "Height =" << height << endl;
		cout << "Area =" << area << endl;
		cout << "Perimeter =" << perimeter << endl;

	}



};