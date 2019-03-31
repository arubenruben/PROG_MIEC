#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include "utilities.hpp"
#include "packs.hpp"


using namespace std;

int last_pack_id=-1;


int read_pack_info(string &filename, vector<Pack>&packs){

    
    ifstream file_read_obj;
    string leitura_aux;
    istringstream istream_aux;
    Pack leitura;
    
    file_read_obj.open(filename.c_str());
    
    if(file_read_obj.fail()){

        cout<<"Erro ao abrir ficheiro"<<endl;
        
        return -1;
    }

    getline(file_read_obj, leitura_aux);
    istream_aux.str(leitura_aux);
    istream_aux >> last_pack_id;

    while(!file_read_obj.eof()){


        getline(file_read_obj, leitura_aux);
        istream_aux.str(leitura_aux);
        istream_aux >> leitura.id;

        getline(file_read_obj, leitura_aux);
        leitura.attraction_point = leitura_aux;
        
        getline(file_read_obj, leitura_aux);
        leitura.data_inicio=leitura_aux;

        getline(file_read_obj, leitura_aux);
        leitura.data_fim=leitura_aux;

        getline(file_read_obj, leitura_aux);
        istream_aux.str(leitura_aux);
        istream_aux >> leitura.price_person;


        getline(file_read_obj, leitura_aux);
        istream_aux.str(leitura_aux);
        istream_aux >> leitura.lugares_inicial;

        getline(file_read_obj, leitura_aux);
        istream_aux.str(leitura_aux);
        istream_aux >> leitura.n_lugares_vendidos;

        file_read_obj.ignore(100,'\n');

        packs.push_back(leitura);
    }



    return 0;
}





