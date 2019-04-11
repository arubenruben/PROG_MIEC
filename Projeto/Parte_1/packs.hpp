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

void display_packs_info(const vector<Pack>&packs);
void display_packs_info(const vector<Pack>&packs, string destination);
void display_packs_info(const vector<Pack>&packs, string destination,string data_inicio,string data_fim);
void display_packs_info(const vector<Pack>&packs, string data_inicio,string data_fim);
int search_pack_by_ID(const vector <Pack>&packs,int id);

void create_new_pack(vector <Pack> &packs);
void delete_pack(vector <Pack> &packs);
void change_pack(vector <Pack> &packs);

void display_packs_by_id(const vector <Pack> &packs,const vector <int> &indices);


