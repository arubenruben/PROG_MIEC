#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
#include <vector>
#include "agency.hpp"
#include "clients.hpp"
#include "packs.hpp"


using namespace std;

extern int last_pack_id;


int main(){

  string filename;
  Agency working_agency;
  vector <Client> clients;
  vector <Pack>packs;
  
  cout<<"Introduzir o nome do ficheiro da agencia"<<endl;
  getline(cin,filename);


  if(read_agency_info(filename,working_agency)!=0){
    return -1;
  }

  
  if(read_client_info(working_agency.file_clients,clients)!=0){
    return -1;
  }

  if(read_pack_info(working_agency.file_travelpacks,packs)!=0){
    return -1;
  }

  display_client_info(clients,1);




  




















  return 0;
}
