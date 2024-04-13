#include "Figure.h"
#include "Figure_manager.h"
#include "Tasks.h"
#include "Input.h"
#include "Files.h"

#include <iostream>

using namespace std;

enum target {
	ADD_CIRCLE = 1,
	ADD_RECTANGLE,
	ADD_TRAPEZOID,
	SHOW_FIGURES,
	SAVE_FIGURES,
	LOAD_FIGURES,
	RUN_TESTS,
	EXIT
};

int main()
{
	system("chcp 65001");
	system("cls");

	int menu_item;

	bool repeat = true;

	Figures_manager figures;

	do {

		menu_item = InputInt("Select menu item : ", 0, 9);

		switch (menu_item)
		{

			case(ADD_CIRCLE): { add_circle(figures); break; }

			case(ADD_RECTANGLE): { add_rectangle(figures); break; }

			case(ADD_TRAPEZOID): { add_trapezoid(figures); break; }

			case(SHOW_FIGURES): { figures.show_figures(); break; }

			case(SAVE_FIGURES): { break; }

			case(LOAD_FIGURES): { break; }

			case(RUN_TESTS): { break; }

			case(EXIT): { repeat = false; }

		}
	
	} while (repeat);


	string filepath = get_valid_filepath();

	vector<shared_ptr<Figure>> figures_from_file = get_employees_from_file(filepath);

	figures.set_figures(figures_from_file);

	figures.show_figures();

	/*vector<shared_ptr<Figure>> figures_to_expotrt = figures.get_figures();



	export_to_file(figures_to_expotrt);*/
}