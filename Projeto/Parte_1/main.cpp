#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
#include <vector>
#include "utilities.hpp"
#include "agency.hpp"
#include "clients.hpp"
#include "packs.hpp"
#include "menu.hpp"

using namespace std;

void program_exec(vector <Client> &clients,vector<Pack> &packs);
void write_at_exit(const Agency working_agency,const vector <Client> &clients,vector <Pack> &packs);

extern int last_pack_id;


int main(){

  string filename;
  string lixo;
  Agency working_agency;
  vector <Client> clients;
  vector <Pack>packs;

  cin.clear();

  
  cout<<"Introduzir o nome do ficheiro da agencia"<<endl;
  getline(cin,filename);
  
  cout<<endl;


  if(read_agency_info(filename,working_agency)!=0){
    return -1;
  }

  
  if(read_client_info(working_agency.file_clients,clients)!=0){
    return -1;
  }

  if(read_pack_info(working_agency.file_travelpacks,packs)!=0){
    return -1;
  }


  
  program_exec(clients,packs);


  write_at_exit(working_agency,clients,packs);


  return 0;
}




void program_exec(vector <Client> &clients,vector<Pack> &packs){

  int read;

  while(1){
    
    cout<<endl;
    cout<<endl;


    cout<<"Escolher uma opcao:"<<endl<<endl;

    cout<<"1-Clientes{Criar,alterar,remover}"<<endl<<endl;

    cout<<"2-Pacotes{Criar,alterar,remover}"<<endl<<endl;
    
    cout<<"3-Display_info{Clients,Packs}"<<endl<<endl;

    cout<<"-1  - Exit"<<endl;

    cin>>read;

    switch (read)
    {
      case 1:

        menu_client(clients,packs);
      
        break;
      case 2:

        menu_pack(clients,packs);
        
        break;
      
      case 3:
        
        menu_display(clients,packs);

        break;
      
      case -1:
        
        return;
        
        break;

      default:
        break;
    }

  }


  return;
}


void write_at_exit(const Agency working_agency,const vector<Client> &clients,vector <Pack> &packs){

  ofstream file_client,file_pack;

  file_client.open(working_agency.file_clients.c_str(),ios::trunc);

  if(file_client.fail()){
    
    cout<<"Erro a abrir file client"<<endl;

    return;
  }



  for(int i=0;i<clients.size();i++){

    file_client<<clients.at(i).name<<endl;
    file_client<<clients.at(i).NIF<<endl;
    file_client<<clients.at(i).N_agregado_familiar<<endl;
    file_client<<clients.at(i).address<<endl;
    file_client<<clients.at(i).bought_packs<<endl;
  
    if(i<clients.size()-1)  {
      file_client<<"::::::::::"<<endl;
    }
    
  }

  file_client.close();

  file_pack.open(working_agency.file_travelpacks.c_str(),ios::trunc);

  if(file_pack.fail()){

    cout<<"Erro a abrir o ficheiro das agencias"<<endl;

    return;
  }
  
  file_pack<<packs.at(packs.size()-1).id<<endl;

  for(int i=0;i<packs.size();i++){
    
    file_pack<<packs.at(i).id<<endl;
    file_pack<<packs.at(i).attraction_point<<endl;
    file_pack<<packs.at(i).data_inicio<<endl;
    file_pack<<packs.at(i).data_fim<<endl;
    file_pack<<packs.at(i).price_person<<endl;
    file_pack<<packs.at(i).lugares_inicial<<endl;
    file_pack<<packs.at(i).n_lugares_vendidos<<endl;
  
    if(i<packs.size()-1) {
      file_pack<<"::::::::::"<<endl;
    }
    
  }


  return;
}

