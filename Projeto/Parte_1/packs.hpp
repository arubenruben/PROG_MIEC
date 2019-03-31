#pragma once


using namespace std;

typedef struct{

    int id;
    string attraction_point;
    string data_inicio;
    string data_fim;
    double price_person;
    int lugares_inicial;
    int n_lugares_vendidos;


}Pack;




int read_pack_info(string &filename, vector<Pack>&packs);
