#pragma once

using namespace std;


typedef struct{

    string name;
    int NIF;
    string URL;
    string address;
    string file_clients;
    string file_travelpacks;

}Agency;

int read_agency_info(string &filename,Agency &return_agency);




