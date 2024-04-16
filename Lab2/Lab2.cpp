#include "Figure.h"
#include "Figure_manager.h"
#include "Tasks.h"
#include "Input.h"
#include "Files.h"
#include "Show_menu.h"

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

	Show_greeting();

	int menu_item;

	bool repeat = true;

	Figures_manager figures;

	do {

		Show_menu();

		menu_item = InputInt("Select menu item : ", 0, 9);

		switch (menu_item)
		{

		case(ADD_CIRCLE): { add_circle(figures); break; }

		case(ADD_RECTANGLE): { add_rectangle(figures); break; }

		case(ADD_TRAPEZOID): { add_trapezoid(figures); break; }

		case(SHOW_FIGURES): { figures.show_figures(); break; }

		case(SAVE_FIGURES): { save_data(figures); break; }

		case(LOAD_FIGURES): { load_data(figures); break; }

		case(RUN_TESTS): { run_tests(); break; }

		case(EXIT): { repeat = false; }

		}

	} while (repeat);

}