#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "clients.hpp"
#include "packs.hpp"
#include "utilities.hpp"

using namespace std;

void menu_display(const vector<Client> &client, const vector<Pack> &packs)
{
  int read;

  while (1)
  {

    cout << "Escolher uma opcao:" << endl
         << endl;

    cout << "1-Ver Cliente" << endl
         << endl; //check

    cout << "2-Ver todos os Clientes" << endl
         << endl; //check

    cout << "3-Ver todos os pacotes disponiveis" << endl
         << endl; //check

    cout << "4-Ver todos os pacotes disponiveis entre datas" << endl
         << endl;

    cout << "5-Ver todos os pacotes disponiveis entre datas para um destino" << endl
         << endl;

    cout << "-1  - Return to main menu" << endl;

    cin >> read;

    switch (read)
    {
    case 1:
    {
      int NIF;

      cout << "Introduza o NIF do cliente" << endl;

      cin >> NIF;

      display_client_info_byNIF(client, NIF);
    }
    break;

    case 2:
    {

      display_client_info(client);
    }

    break;

    case 3:
    {

      display_packs_info(packs);
    }
    break;

    case 4: //check
    {
      string data_inicio, data_fim;
      cout << "Introduzir data no formato ano/mes/dia" << endl;
      cout << "Data de inicio" << endl;
      cin >> data_inicio;
      cout << "Data de fim" << endl;
      cin >> data_fim;

      display_packs_info(packs, data_inicio, data_fim);
    }
    break;

    case 5:
    {

      string data_inicio, data_fim, destino;

      cout << "Introduzir data no formato ano/mes/dia" << endl;
      cout << "Data de inicio" << endl;
      cin >> data_inicio;
      cout << "Data de fim" << endl;
      cin >> data_fim;
      cout << "Destino" << endl;
      cin >> destino;

      display_packs_info(packs, destino, data_inicio, data_fim);
    }

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
void menu_client(vector<Client> &clients, vector<Pack> &packs)
{

  int read;

  while (1)
  {

    cout << "Introduza uma opcao" << endl;
    cout << "1-Criar Cliente" << endl;
    cout << "2-Alterar Cliente" << endl;
    cout << "3-Remove Cliente" << endl;
    cout << "4-Pacotes vendidos a um cliente" << endl;
    cout << "5-Pacotes vendidos a todos os clientes" << endl;
    cout << "6-Efetuar uma compra" << endl;

    cout << "-1) Retornar ao menu principal" << endl;

    cin >> read;

    switch (read)
    {
    case 1:
    { //check

      cout << "Caso pretenda anular primir" << endl;
      create_new_client(clients, packs);
    }

    break;

    case 2:
    { //check
      change_client(clients);
    }
    break;

    case 3:
    { //check

      delete_client(clients);
    }
    case 4:
    { //check

      int NIF;
      int indice_ID_cliente;

      string packs_bought;

      vector<int> indices;

      cout << "Introduzir o NIF do cliente" << endl;
      cin >> NIF;

      if (indice_ID_cliente = NIF_search(clients, NIF) == -1)
      {
        cout << "Cliente Inexistente, inserir primeiro" << endl;
      }

      packs_bought = clients.at(indice_ID_cliente).bought_packs;

      id_packs_client_bought(packs_bought, indices);

      display_packs_by_id(packs, indices);
    }

    case 5:
    {

      for (int i = 0; i < clients.size(); i++)
      {

        int NIF;

        string packs_bought;

        vector<int> indices;

        packs_bought = clients.at(i).bought_packs;

        id_packs_client_bought(packs_bought, indices);

        cout << "Cliente:" << clients.at(i).name << "Comprou:" << endl;

        display_packs_by_id(packs, indices);
      }
    }

    break;

    case 6:{
      
      purchase(clients,packs);


    }
    break;

    case -1:
    {

      return;
    }
    break;

    default:
      cout << "Entrada invalida" << endl;
      break;
    }
  }
  return;
}

void menu_pack(vector<Client> &clients, vector<Pack> &packs)
{
  int read;

  while (1)
  {

    cout << "Introduza uma opcao" << endl;
    cout << "1-Criar Pack" << endl;
    cout << "2-Alterar Pack" << endl;
    cout << "3-Remove Pack" << endl;
    cout << "4-Pacotes vendidos a um cliente" << endl;
    cout << "5-Pacotes vendidos a todos os clientes" << endl;
    cout << "-1) Retornar ao menu principal" << endl;

    cin >> read;

    switch (read)
    {
    case 1:
    { //check

      cout << "Caso pretenda anular primir" << endl;

      create_new_pack(packs);
    }

    break;

    case 2:
    { //check

      change_pack(packs);
    }
    break;

    case 3:
    { //check

      delete_pack(packs);
    }
    break;
    case -1:
    {

      return;
    }
    break;

    default:
      cout << "Entrada invalida" << endl;
      break;
    }
  }
  return;
}