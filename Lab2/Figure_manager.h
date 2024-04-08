#pragma once

#include"Figure.h"

#include <iostream>
#include <vector>



class Figure_manager
{
private:
	
	vector <Figure*> figures;

public:

	void add_figure(Figure *figure) { figures.push_back(figure); }

	void show_figures() {

		cout << endl;

		if (figures.empty()) { cout << "You haven't added any figure yet" << endl; return; }

		for (auto* figure : figures ) { figure->show_figure(); }

		cout << endl;
	}

	void set_figures(vector<Figure*> new_figures) {this->figures = new_figures;}

	vector<Figure*> get_figures() { return figures; }








};
