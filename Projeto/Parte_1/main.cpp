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


using namespace std;

extern int last_pack_id;

void program_exec();

int main(){

  string filename;
  Agency working_agency;
  vector <Client> clients;
  vector <Pack>packs;
  
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

  program_exec();







  return 0;
}




void program_exec(){

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

    if(read==-1){
      break;
    }

  }


  return;
}




