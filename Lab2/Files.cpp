#include "Figure.h"
#include "Input.h"

#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
#include <vector>

using namespace std;

bool file_exists(string filename) {
	ifstream file(filename);
	return file.is_open();
}

bool confirm_overwrite(string filename) {

	const int YES = 1;

	cout << "File '" << filename << "' already exists." << endl;
	cout << "Do you want to overwrite it?" << endl;
	cout << "1 - Yes" << endl;
	cout << "2 - No" << endl;

	int user_choice = 0;

	user_choice = InputInt("Enter menu item:", 0, 3);

	if (user_choice == YES) { return true; }

	return false;

}

vector<shared_ptr<Figure>> get_employees_from_file(string filename) {
	vector<shared_ptr<Figure>> files;

	ifstream input_file(filename);
	if (!input_file.is_open()) {
		cerr << "Error opening file: " << filename << endl;
		return files;
	}

	string line;
	while (getline(input_file, line)) {

		if (line.empty()) {
			cerr << "Warning: Skipped empty line." << endl;
			continue;
		}

		const int NAME = 0;

		const int RADIUS = 1;
		const int CIRCLE_AREA = 2;
		const int CIRCLE_PERIMETER = 3;

		const int LENGTH = 1;
		const int WIDTH = 2;
		const int RECTANGLE_AREA = 3;
		const int RECTANGLE_PERIMETER = 4;

		const int RIGTH_SIDE = 1;
		const int LEFT_SIDE = 2;
		const int TOP_BASE = 3;
		const int BOTTOM_BASE = 4;
		const int HEIGHT = 5;
		const int TRAPEZOID_AREA = 6;
		const int TRAPEZOID_PERIMETER = 7;

		stringstream ss(line);

		string token{ "" };


		int field_count = 0;

		double radius = 0;

		double length = 0;
		double width = 0;

		double right_side = 0;
		double left_side = 0;
		double top_base = 0;
		double bottom_base = 0;
		double height = 0;

		if (line[0] == 'C') {
			while (getline(ss, token, ';')) {
				try {

					switch (field_count) {

					case NAME: break;

					case RADIUS: radius = stod(token); break;

					case CIRCLE_AREA:break;

					case CIRCLE_PERIMETER:break;

					default:
						cerr << "Warning: parsing " << field_count << " field: " << "wrong number of fields" << endl;

					}

				}
				catch (invalid_argument& e) {
					cerr << "Warning: converting field " << field_count << ": " << e.what() << endl;
				}
				field_count++;
			}
			if (radius <= 0) {
				files.clear();
				input_file.close();
				return files;
			}

			files.push_back(make_shared<Circle>(radius));
		}
		if (line[0] == 'R') {
			while (getline(ss, token, ';')) {
				try {

					switch (field_count) {

						case NAME: break;

						case LENGTH: length = stod(token); break;

						case WIDTH: width = stod(token); break;

						case RECTANGLE_AREA:break;

						case RECTANGLE_PERIMETER: break;

						default:
							cerr << "Warning: parsing " << field_count << " field: " << "wrong number of fields" << endl;

					}
				}
				catch (invalid_argument& e) {
					cerr << "Warning: converting field " << field_count << ": " << e.what() << endl;
				}
				field_count++;
			}
			if (length <= 0 || width <= 0) {
				files.clear();
				input_file.close();
				return files;
			}

			files.push_back(make_shared<Rectangle>(length,width));

		}
		if (line[0] == 'T') {
			while (getline(ss, token, ';')) {
				try {

					switch (field_count) {

						case NAME: break;

						case RIGTH_SIDE: right_side = stod(token); break;

						case LEFT_SIDE: left_side = stod(token); break;

						case TOP_BASE: top_base = stod(token); break;

						case BOTTOM_BASE: bottom_base = stod(token); break;

						case HEIGHT: height = stod(token); break;

						case TRAPEZOID_AREA:break;

						case TRAPEZOID_PERIMETER: break;

						default:
							cerr << "Warning: parsing " << field_count << " field: " << "wrong number of fields" << endl;

					}
				}
				catch (invalid_argument& e) {
					cerr << "Warning: converting field " << field_count << ": " << e.what() << endl;
				}
				field_count++;
			}

			if (right_side <= 0 || left_side <= 0 || top_base <= 0 || bottom_base <= 0 || height <=0 ) {
				files.clear();
				input_file.close();
				return files;
			}

			files.push_back(make_shared<Trapezoid>(right_side, left_side, top_base, bottom_base, height));

		}

	}

	input_file.close();
	return files;	
}

bool is_filepath_valid(string filepath) {

	regex file_path_regex("^(?:[a-zA-Z]\\:|\\\\)\\\\([^\\\\]+\\\\)*[^\\/:*?\"<>|]+\\.csv$");

	if (!regex_match(filepath, file_path_regex)) {
		cerr << "Error: Invalid file path." << endl;
		return false;
	}

	return true;
}
bool is_filename_valid(string filename) {
	regex filename_regex("^[^\\/:*?\"<>|]+\\.csv$");

	regex filename_reserved_names("^(?:CON|PRN|AUX|NUL|COM[1-9]|LPT[1-9]|con|prn|aux|nul|com[1-9]|lpt[1-9])(?:\\..*)?$");

	regex filename_reserved_chars("[\\/:*?\'<>|]");

	if (!regex_match(filename, filename_regex)) {
		cerr << "Error: Invalid file name." << endl;
		return false;
	}

	if (regex_match(filename, filename_reserved_names)) {
		cerr << "Error: Invalid file name. Using reserved filenames is prohibited!" << endl;
		return false;
	}

	if (regex_search(filename, filename_reserved_chars)) {
		cerr << "Error: Invalid file name. Using reserved characters is prohibited!" << endl;
		return false;
	}

	return true;
}

string get_valid_filepath() {
	bool is_path_valid = false;
	bool is_name_valid = false;

	string filename{ "" };
	string filepath{ "" };

	while (!is_path_valid || !is_name_valid) {
		filename = InputString("Enter filename (only csv acceptable): ");

		filepath = InputString("Enter full path to path: ");

		if (is_filepath_valid(filepath + filename) && is_filename_valid(filename)) {
			is_path_valid = true;
			is_name_valid = true;
		}
	}

	return filepath + filename;
}

string get_overwrite_confirmation(string full_path) {
	while (file_exists(full_path)) {
		if (confirm_overwrite(full_path)) {
			return full_path;
		}
		else {
			cout << "Please choose another file." << endl;
			return get_valid_filepath();
		}
	}
	return full_path;
}
void export_to_file(vector<shared_ptr<Figure>> figures_to_export) {

	string full_path = get_valid_filepath();
	full_path = get_overwrite_confirmation(full_path);

	ofstream file(full_path);
	if (!file) {
		cerr << "Error: File is read-only or another error occurred." << endl;
		file.close();

		while (true) {
			cout << "Please enter a new path." << endl;
			full_path = get_valid_filepath();
			full_path = get_overwrite_confirmation(full_path);

			file.open(full_path);
			if (file) {
				break;
			}
			else {
				cerr << "Error: File is read-only or another error occurred." << endl;
				file.close();
			}
		}
	}

	for (auto& export_figures : figures_to_export) {

		if (export_figures -> get_name() == 'C') {

			file << export_figures->get_name() << ";"
				<< export_figures->get_fields()[0] << ";"
				<<export_figures->area()<< ";"
				<<export_figures->perimeter()<< "\n";
		}
		if (export_figures->get_name() == 'R') {

			file << export_figures -> get_name() << ";"
				<< export_figures->get_fields()[0] <<";"
				<< export_figures->get_fields()[1] <<";"
				<< export_figures->area() << ";"
				<< export_figures->perimeter() << "\n";
		}
		if (export_figures->get_name() == 'T') {

			file << export_figures->get_name() << ";" 
				<< export_figures->get_fields()[0] << ";"
				<< export_figures->get_fields()[1] << ";"
				<< export_figures->get_fields()[2] << ";"
				<< export_figures->get_fields()[3] << ";"
				<< export_figures->get_fields()[4] << ";"
				<< export_figures->area() << ";"
				<< export_figures->perimeter() << "\n";

		}
	}

	file.close();
	cout << "Data successfully exported to file: " << full_path << endl;
}