#pragma once

#include"Figure.h"

#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;


class Figures_manager
{
private:
	
	vector <shared_ptr<Figure>> figures;

public:

	void add_figure(shared_ptr<Figure> figure) { figures.push_back(figure); }

	void show_figures() {

		cout << endl;

		if (figures.empty()) { cout << "You haven't added any figure yet" << endl; return; }

		for (auto& figure : figures ) { figure->show_figure(); }

		cout << endl;
	}

	void set_figures(vector<shared_ptr<Figure>> &new_figures) { figures = new_figures;}

	vector<shared_ptr<Figure>> get_figures() { return figures; }









};
