#pragma once

#include "vector"

using namespace std;

string read_address(ifstream &file_read_obj);

void date_parsing(string date, int *ano, int *mes, int *dia);
void id_packs_client_bought(string str_to_transform, vector <int> &id_packs_bought);

