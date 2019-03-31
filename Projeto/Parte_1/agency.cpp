#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
#include <cstring>
#include <stdlib.h>
#include "agency.hpp"
#include "utilities.hpp"


using namespace std;



int read_agency_info(string &filename,Agency &return_agency){


    ifstream file_read_obj;
    string leitura_aux;
    Agency local_agency;
    istringstream istream_aux;
    
    file_read_obj.open(filename.c_str());
    
    if(file_read_obj.fail()){

        cout<<"Erro ao abrir ficheiro"<<endl;
        
        return -1;
    }

    getline(file_read_obj,leitura_aux);
    local_agency.name=leitura_aux;

    getline(file_read_obj,leitura_aux);
    istream_aux.str(leitura_aux);
    istream_aux>>local_agency.NIF;

    getline(file_read_obj,leitura_aux);
    local_agency.URL=leitura_aux;

    //ler a morada:
    



    string morada_completa;

    leitura_aux=read_address(file_read_obj);

    if(leitura_aux!="erro"){
        local_agency.address=leitura_aux;
    }else{
        cout<<"Erro na morada da agencia"<<endl;
        return -1;
    }


    local_agency.address=morada_completa;

   

//Clientes file
    
    getline(file_read_obj,leitura_aux);
    
   
    local_agency.file_clients=leitura_aux;
    
  //Travel_packs file

    getline(file_read_obj,leitura_aux);
    local_agency.file_travelpacks=leitura_aux;
    
    
    ifstream file_test;


    file_test.open(local_agency.file_clients.c_str());
    
    if(file_test.fail()){
        cout<<"Falhou a abrir os ficheiros auxiliares de client"<<endl;
        return -1;
    }
    file_test.close();

    file_test.open(local_agency.file_travelpacks.c_str());
    

    if(file_test.fail()){
        cout<<"Falhou a abrir os ficheiros auxiliares de travelpack"<<endl;
        return -1;
    }

    file_test.close();


    return_agency= local_agency;


    return 0;
}



