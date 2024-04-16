#pragma once

#define _USE_MATH_DEFINES
#include <iostream>
#include <math.h>
#include <vector>

using namespace std;

class Figure
{
protected:

	



public:

	virtual double area() = 0;
	virtual double perimeter() = 0;

	virtual void show_figure() = 0;

	virtual char get_name() = 0;

	virtual vector<double> get_fields() = 0;

};

class Circle :public Figure
{

private:

	double radius;

	vector<double>fields{radius,area(),perimeter()};

public:

	Circle(double radius) : radius(radius) {}

	double area() override { return radius * radius * M_PI; }
	double perimeter() override { return 2 * M_PI * radius; }

	void show_figure() override {

		cout << "This is a figure circle:" << endl;
		cout << "Radius = " << radius << endl;
		cout << "Area = " << area() << endl;
		cout << "Perimeter = " << perimeter() << endl;
		cout << endl;

	}

	char get_name() override { return 'C'; }

	double get_radius() { return radius; }

	vector<double> get_fields() override { return fields; }

};

class Rectangle :public Figure
{

private:

	double length;
	double width;

	vector<double>fields{ length, width, area(), perimeter() };

public:

	Rectangle(double length, double width) : length(length), width(width) {}

	double area() override { return length * width; }
	double perimeter() override { return 2 * (length + width); }

	void show_figure() override {

		cout << "This is a figure rectangle:" << endl;
		cout << "Length = " << length << endl;
		cout << "Width = " << width << endl;
		cout << "Area = " << area() << endl;
		cout << "Perimeter = " << perimeter() << endl;
		cout << endl;

	}

	char get_name() override { return 'R'; }

	double get_length() { return length; }
	double get_width() { return width; }

	vector<double> get_fields() override { return fields; }

};

class Trapezoid :public Figure
{

private:

	double right_side;
	double left_side;
	double top_base;
	double bottom_base;
	double height;

	vector<double>fields{ right_side, left_side, top_base, bottom_base, height, area(), perimeter() };
	
public:

	Trapezoid(double right_side, double left_side, double top_base, double bottom_base, double height) :
		right_side(right_side), left_side(left_side), top_base(top_base), bottom_base(bottom_base), height(height) {}

	double area() override { return height * (top_base + bottom_base) / 2; }
	double perimeter() override { return right_side + left_side + top_base + bottom_base; }

	void show_figure() override {

		cout << "This is a figure trapezoid:" << endl;
		cout << "Right side = " << right_side << endl;
		cout << "Left side = " << left_side << endl;
		cout << "Top base = " << top_base << endl;
		cout << "Bottom base = " << bottom_base << endl;
		cout << "Height = " << height << endl;
		cout << "Area = " << area() << endl;
		cout << "Perimeter = " << perimeter() << endl;
		cout << endl;

	}

	char get_name() override { return 'T'; }

	double get_rigth_side() { return right_side; }
	double get_left_side() { return left_side; }
	double get_top_base() { return top_base; }
	double get_bottom_base() { return bottom_base; }
	double get_heigth() { return height; }

	vector<double> get_fields() override { return fields; }

};