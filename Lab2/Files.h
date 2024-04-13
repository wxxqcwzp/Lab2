#pragma once

#include "Figure.h"

#include <iostream>
#include <vector>

using namespace std;

bool file_exists(string filename);

bool confirm_overwrite(string filename);

vector<shared_ptr<Figure>> get_employees_from_file(string fileName);

void export_to_file(vector<shared_ptr<Figure>> employees_to_export);

bool is_filepath_valid(string filepath);

bool is_filename_valid(string filename);

string get_valid_filepath();
