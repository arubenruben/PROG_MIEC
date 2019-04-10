#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include "clients.hpp"
#include "packs.hpp"

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

    case 4: //faulty. Resolver bug na procura de datas dos packs
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

    case 5:{

      string data_inicio, data_fim,destino;

      cout << "Introduzir data no formato ano/mes/dia" << endl;
      cout << "Data de inicio" << endl;
      cin >> data_inicio;
      cout << "Data de fim" << endl;
      cin >> data_fim;
      cout << "Destino"<<endl;
      cin>>destino;

      display_packs_info(packs,destino,data_inicio,data_fim);


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
