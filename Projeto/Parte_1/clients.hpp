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
void display_client_info_byPos(const vector<Client>&clients, unsigned int pos);
void display_client_info_byNIF(const vector<Client> &clients, int NIF);



