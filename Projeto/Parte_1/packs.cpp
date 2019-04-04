#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
#include <string>
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
    
    istream_aux.clear();
    istream_aux.str(leitura_aux);
    istream_aux >> last_pack_id;

    istream_aux.clear();
    istream_aux.ignore(10000,'\n');

    while(!file_read_obj.eof()){


                
        file_read_obj>>leitura.id;
        
        file_read_obj.ignore(10000,'\n');

        getline(file_read_obj, leitura_aux);
        leitura.attraction_point = leitura_aux;
        
        getline(file_read_obj, leitura_aux);
        leitura.data_inicio=leitura_aux;

        getline(file_read_obj, leitura_aux);
        leitura.data_fim=leitura_aux;

        getline(file_read_obj, leitura_aux);
        
        


        istream_aux.clear();
        istream_aux.str(leitura_aux.c_str());
        
        
        istream_aux >> leitura.price_person;


        getline(file_read_obj, leitura_aux);
        
        istream_aux.clear();
        istream_aux.str(leitura_aux.c_str());
        istream_aux >> leitura.lugares_inicial;

        getline(file_read_obj, leitura_aux);
        istream_aux.clear();

        istream_aux.str(leitura_aux.c_str());
        istream_aux >> leitura.n_lugares_vendidos;

        file_read_obj.ignore(100,'\n');

        packs.push_back(leitura);
    }


    file_read_obj.close();

    return 0;
}


void display_packs_info(const vector<Pack>&packs){

    for(int i=0;i<packs.size();i++){
        
        cout<<packs.at(i).id<<endl;
        cout<<packs.at(i).attraction_point<<endl;
        cout<<packs.at(i).data_inicio<<endl;
        cout<<packs.at(i).data_fim<<endl;
        cout<<packs.at(i).price_person<<endl;
        cout<<packs.at(i).lugares_inicial<<endl;
        cout<<packs.at(i).n_lugares_vendidos<<endl;

        cout<<"::::::::::"<<endl;

    }

    return;
}

void display_packs_info(const vector<Pack>&packs, string destination){

    int count=0;
    
    for(int i=0;i<packs.size();i++){
        
        if(packs.at(i).attraction_point.find(destination)!=string::npos){
            cout<<packs.at(i).id<<endl;
            cout<<packs.at(i).attraction_point<<endl;
            cout<<packs.at(i).data_inicio<<endl;
            cout<<packs.at(i).data_fim<<endl;
            cout<<packs.at(i).price_person<<endl;
            cout<<packs.at(i).lugares_inicial<<endl;
            cout<<packs.at(i).n_lugares_vendidos<<endl;

            cout<<"::::::::::"<<endl;
            count++;
        }

    }


    if(count==0){
        cout<<"No packs to display with that destination"<<endl;
    }

    return;
}

void display_packs_info(const vector<Pack>&packs, string destination,string data_inicio,string data_fim){

    int count=0;
    
    for(int i=0;i<packs.size();i++){
        
        if((packs.at(i).attraction_point.find(destination)!=string::npos)&&
        ((date_to_seconds(data_inicio)>=(date_to_seconds(packs.at(i).data_inicio))))&&
        ((date_to_seconds(data_fim))<=(date_to_seconds(packs.at(i).data_fim))))
        {
            
            cout<<packs.at(i).id<<endl;
            cout<<packs.at(i).attraction_point<<endl;
            cout<<packs.at(i).data_inicio<<endl;
            cout<<packs.at(i).data_fim<<endl;
            cout<<packs.at(i).price_person<<endl;
            cout<<packs.at(i).lugares_inicial<<endl;
            cout<<packs.at(i).n_lugares_vendidos<<endl;

            cout<<"::::::::::"<<endl;
            count++;
        }

    }


    if(count==0){
        cout<<"No packs to display with that destination"<<endl;
    }

    return;
}

void display_packs_info(const vector<Pack>&packs, string data_inicio,string data_fim){int count=0;
    
    for(int i=0;i<packs.size();i++){
        
        if(
        ((date_to_seconds(data_inicio)>=(date_to_seconds(packs.at(i).data_inicio))))&&
        ((date_to_seconds(data_fim))<=(date_to_seconds(packs.at(i).data_fim))))
        {
            
            cout<<packs.at(i).id<<endl;
            cout<<packs.at(i).attraction_point<<endl;
            cout<<packs.at(i).data_inicio<<endl;
            cout<<packs.at(i).data_fim<<endl;
            cout<<packs.at(i).price_person<<endl;
            cout<<packs.at(i).lugares_inicial<<endl;
            cout<<packs.at(i).n_lugares_vendidos<<endl;

            cout<<"::::::::::"<<endl;
            count++;
        }

    }


    if(count==0){
        cout<<"No packs to display with that destination"<<endl;
    }

    return;
}



