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
#include "packs.hpp"


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
        
        istream_aux.clear();

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
            cout << "Erro na morada do client" << endl;
            cout<<leitura.name<<endl;
            return -1;
        }

        leitura.address = leitura_aux;
        
        getline(file_read_obj, leitura_aux);
       
        
        leitura.bought_packs=leitura_aux;
        
        file_read_obj.ignore(100,'\n');

        clients.push_back(leitura);

        int i=clients.size();
        i--;


    }

    file_read_obj.close();


    return 0;
}






void display_client_info(const vector<Client>&clients){

    cout<<endl;
    
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


void display_client_info_byPos(const vector<Client> &clients, unsigned int pos)
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




void display_client_info_byNIF(const vector<Client>&clients,int NIF){

    if(NIF==-1){
        cout<<"NIF e -1, erro"<<endl;
        exit(-1);
    }
    
    for(u_int i=0;i<clients.size();i++){

        if(NIF==clients.at(i).NIF){
            cout<<endl;
            cout<<clients.at(i).name<<endl;
            cout<<clients.at(i).NIF<<endl;
            cout<<clients.at(i).N_agregado_familiar<<endl;
            cout<<clients.at(i).address<<endl;
            cout<<clients.at(i).bought_packs<<endl;
            
            cout<<"::::::::::"<<endl;
            return;
        }


    }

    cout<<"Cliente inexistente"<<endl;

    return;
}


void create_new_client(vector <Client> &clients,const vector <Pack> &packs){

    Client temporario;
    string leituras;
    int id_leitura;
    int control_helper=1;
    ostringstream ostr;


        int NIF;
        int agregado;
        cin.clear();
        cin.ignore(1000,'\n');

        cout<<"Introduzir o nome do client"<<endl;
        
        getline(cin,leituras);
        temporario.name=leituras;


        cout<<"Introduzir o NIF do client"<<endl;
        cin>>NIF;

        if(NIF_search(clients,NIF)!=-1){
            cout<<"Cliente ja existente, usar a opcao alterar"<<endl;
            return;
        }
        temporario.NIF=NIF;

        cout<<"Introduzir o Agregado familiar"<<endl;
        cin>>agregado;
        temporario.N_agregado_familiar=agregado;

        cout<<"Introduzir a morada do cliente no formato Rua/N_Porta/Andar/Codigo-Postal/Localidade"<<endl;
        
        cin.clear();
        cin.ignore(1000,'\n');


        getline(cin,leituras);
        temporario.address=leituras;
        
        
        ostr.clear();
    

    int contador=0;
    
    while(control_helper){


        cout<<"Introduzir o ID da viagem comprada pelo cliente"<<endl;
        cin>>id_leitura;
        

        if(search_pack_by_ID(packs,id_leitura)==0){
            cout<<"Viagem nao disponivel tente novamente"<<endl;
            continue;
        }else{
            if(contador>0){
                ostr<<";";
            }
            contador++;
            ostr<<id_leitura;
        }  

        temporario.bought_packs=ostr.str();

        
        cout<<"Pretende introduzir mais viagens a este cliente?"<<endl<<"Se sim, prima 1, caso contrario, prima 0"<<endl;
        cin>>control_helper;
        
        ostr.flush();
    }
    
    clients.push_back(temporario);

    return;
}


int NIF_search(const vector<Client>&clients,int NIF){


    for(u_int i=0;i<clients.size();i++){

        if(NIF==clients.at(i).NIF){
            return i;
        }
    }

    return -1;
}


void delete_client(vector <Client> &clients){


    for(int i=0;i<clients.size();i++){
        
        system("clear");

        int is_this=0;

        cout << endl;
        cout << clients.at(i).name << endl;
        cout << clients.at(i).NIF << endl;
        cout << clients.at(i).N_agregado_familiar << endl;
        cout << clients.at(i).address << endl;
        cout << clients.at(i).bought_packs << endl;

        cout<<"E este o client a apagar, se sim, digitar 1, se nao digitar outra tecla"<<endl;

        cin>>is_this;

        if(is_this==1){

            clients.erase(clients.begin()+i);            

        }

        
    }



    return;
}

void change_client(vector <Client> &clients){


    for(int i=0;i<clients.size();i++){
        
        system("clear");

        int is_this=0;

        cout << endl;
        cout << clients.at(i).name << endl;
        cout << clients.at(i).NIF << endl;
        cout << clients.at(i).N_agregado_familiar << endl;
        cout << clients.at(i).address << endl;
        cout << clients.at(i).bought_packs << endl;

        cout<<"E este o client a alterar, se sim, digitar 1, se nao digitar outra tecla"<<endl;

        cin>>is_this;
        cin.clear();
        cin.ignore(1000,'\n');

        if(is_this==1){
            
            cout<<endl;
            cout<<endl;

            cout<<"Introduzir novo nome"<<endl;
            getline(cin,clients.at(i).name);
            cout<<"Introduzir novo NIF"<<endl;
            cin>>clients.at(i).NIF;
            cout<<"Introduzir novo agregado familiar"<<endl;
            cin>>clients.at(i).N_agregado_familiar;
            cout<<"Nova Morada no formato Rua/porta/andar/codigo-postal/Localidade"<<endl;
            cin.clear();
            cin.ignore(1000,'\n');
            getline(cin,clients.at(i).address);
            cout<<"Listar packs comprados no formato n ou n;n;n(caso multiplo)"<<endl;
            getline(cin,clients.at(i).bought_packs);

            return;


        }

        
    }



    return;
}



