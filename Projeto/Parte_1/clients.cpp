#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
#include <cstring>
#include <stdlib.h>
#include <vector>
#include "clients.hpp"
#include "utilities.hpp"


using namespace std;


int read_client_info(string &filename, vector<Client>&clients){

    
    ifstream file_read_obj;
    string leitura_aux;
    istringstream istream_aux;
    Client leitura;
    
    file_read_obj.open(filename.c_str());
    
    if(file_read_obj.fail()){

        cout<<"Erro ao abrir ficheiro"<<endl;
        
        return -1;
    }

    while(!file_read_obj.eof()){

        getline(file_read_obj, leitura_aux);
        leitura.name = leitura_aux;
        //cout<<leitura.name;

        getline(file_read_obj, leitura_aux);
        istream_aux.str(leitura_aux);
        istream_aux >> leitura.NIF;

        istream_aux.clear(); //sem isto estava a dar um bug que nao lia o agregado na stream?????
        


        getline(file_read_obj, leitura_aux);
        istream_aux.str(leitura_aux);
        istream_aux >> (leitura.N_agregado_familiar);


        //ler a morada:

       

        leitura_aux = read_address(file_read_obj);

        if (leitura_aux != "erro")
        {
            leitura.address = leitura_aux;
        }
        else
        {
            cout << "Erro na morada da agencia" << endl;
            return -1;
        }

        leitura.address = leitura_aux;
        
        getline(file_read_obj, leitura_aux);
       
        
        leitura.bought_packs=leitura_aux;
        
        file_read_obj.ignore(100,'\n');

        clients.push_back(leitura);
    }



    return 0;
}






void display_client_info(const vector<Client>&clients){

    for(u_int i=0;i<clients.size();i++){

        cout<<clients.at(i).name<<endl;
        cout<<clients.at(i).NIF<<endl;
        cout<<clients.at(i).N_agregado_familiar<<endl;
        cout<<clients.at(i).address<<endl;
        cout<<clients.at(i).bought_packs<<endl;
        
        cout<<"::::::::::"<<endl;


    }

    return;
}


void display_client_info(const vector<Client> &clients, unsigned int pos)
{

    if (clients.size() > pos && pos >= 0){
        cout << clients.at(pos).name << endl;
        cout << clients.at(pos).NIF << endl;
        cout << clients.at(pos).N_agregado_familiar << endl;
        cout << clients.at(pos).address << endl;
        cout << clients.at(pos).bought_packs << endl;

        cout << "::::::::::" << endl;
    }

    return ;
}
