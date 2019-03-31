#pragma once


using namespace std;

typedef struct{

    string name;
    
    int NIF;
    int N_agregado_familiar;
    string address;
    string bought_packs;

}Client;



int read_client_info(string &filename, vector<Client>&clients);

void display_client_info(const vector<Client>&clients);
void display_client_info(const vector<Client>&clients, unsigned int pos);




