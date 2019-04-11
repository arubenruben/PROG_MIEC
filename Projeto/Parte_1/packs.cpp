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

int last_pack_id = -1;

int read_pack_info(string &filename, vector<Pack> &packs)
{

    ifstream file_read_obj;
    string leitura_aux;
    istringstream istream_aux;
    Pack leitura;

    file_read_obj.open(filename.c_str());

    if (file_read_obj.fail())
    {

        cout << "Erro ao abrir ficheiro" << endl;

        return -1;
    }

    getline(file_read_obj, leitura_aux);

    istream_aux.clear();
    istream_aux.str(leitura_aux);
    istream_aux >> last_pack_id;

    istream_aux.clear();
    istream_aux.ignore(10000, '\n');

    while (!file_read_obj.eof())
    {

        file_read_obj >> leitura.id;

        file_read_obj.ignore(10000, '\n');

        getline(file_read_obj, leitura_aux);
        leitura.attraction_point = leitura_aux;

        getline(file_read_obj, leitura_aux);
        leitura.data_inicio = leitura_aux;

        getline(file_read_obj, leitura_aux);
        leitura.data_fim = leitura_aux;

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

        file_read_obj.ignore(100, '\n');

        packs.push_back(leitura);
    }


    int last_indice;

    last_indice=packs.size();

    last_pack_id=packs.at(last_indice-1).id;

    file_read_obj.close();

    return 0;
}

void display_packs_info(const vector<Pack> &packs)
{
    cout << endl;
    for (int i = 0; i < packs.size(); i++)
    {

        cout << packs.at(i).id << endl;
        cout << packs.at(i).attraction_point << endl;
        cout << packs.at(i).data_inicio << endl;
        cout << packs.at(i).data_fim << endl;
        cout << packs.at(i).price_person << endl;
        cout << packs.at(i).lugares_inicial << endl;
        cout << packs.at(i).n_lugares_vendidos << endl;

        cout << "::::::::::" << endl;
    }

    return;
}

void display_packs_info(const vector<Pack> &packs, string destination)
{

    int count = 0;

    for (int i = 0; i < packs.size(); i++)
    {

        if (packs.at(i).attraction_point.find(destination) != string::npos)
        {
            cout << packs.at(i).id << endl;
            cout << packs.at(i).attraction_point << endl;
            cout << packs.at(i).data_inicio << endl;
            cout << packs.at(i).data_fim << endl;
            cout << packs.at(i).price_person << endl;
            cout << packs.at(i).lugares_inicial << endl;
            cout << packs.at(i).n_lugares_vendidos << endl;

            cout << "::::::::::" << endl;
            count++;
        }
    }

    if (count == 0)
    {
        cout << "No packs to display with that destination" << endl;
    }

    return;
}

void display_packs_info(const vector<Pack> &packs, string destination, string data_inicio, string data_fim)
{

    int count = 0;

    int ano_parametro_inicio, ano_parametro_fim, mes_parametro_inicio, mes_parametro_fim, dia_parametro_inicio, dia_parametro_fim;

    date_parsing(data_inicio, &ano_parametro_inicio, &mes_parametro_inicio, &dia_parametro_inicio);
    date_parsing(data_fim, &ano_parametro_fim, &mes_parametro_fim, &dia_parametro_fim);
    /*
    cout<<ano_parametro_inicio<<mes_parametro_inicio<<dia_parametro_inicio<<endl;
    cout<<ano_parametro_fim<<mes_parametro_fim<<dia_parametro_fim<<endl;
*/

    for (int i = 0; i < packs.size(); i++)
    {

        int ano_temp_inicio, ano_temp_fim, mes_temp_inicio, mes_temp_fim, dia_temp_inicio, dia_temp_fim;

        date_parsing(packs.at(i).data_inicio, &ano_temp_inicio, &mes_temp_inicio, &dia_temp_inicio);

        date_parsing(packs.at(i).data_fim, &ano_temp_fim, &mes_temp_fim, &dia_temp_fim);
        /*
        cout<<ano_temp_inicio<<mes_temp_inicio<<dia_temp_inicio<<endl;
        cout<<ano_temp_fim<<mes_temp_fim<<dia_temp_fim<<endl;
*/

        if ((ano_parametro_inicio >= ano_temp_inicio && ano_parametro_fim <= ano_temp_fim) && (mes_parametro_inicio >= mes_temp_inicio && mes_parametro_fim <= mes_temp_fim) &&
            (dia_parametro_inicio >= dia_temp_inicio && dia_parametro_fim <= dia_temp_fim) && (packs.at(i).attraction_point.find(destination) != string::npos))
        {
            cout << packs.at(i).id << endl;
            cout << packs.at(i).attraction_point << endl;
            cout << packs.at(i).data_inicio << endl;
            cout << packs.at(i).data_fim << endl;
            cout << packs.at(i).price_person << endl;
            cout << packs.at(i).lugares_inicial << endl;
            cout << packs.at(i).n_lugares_vendidos << endl;

            cout << "::::::::::" << endl;
            count++;
        }
    }

    if (count == 0)
    {
        cout << "No packs to display with on that period of time" << endl;
    }

    return;
}

void display_packs_info(const vector<Pack> &packs, string data_inicio, string data_fim)
{

    int count = 0;

    int ano_parametro_inicio, ano_parametro_fim, mes_parametro_inicio, mes_parametro_fim, dia_parametro_inicio, dia_parametro_fim;

    date_parsing(data_inicio, &ano_parametro_inicio, &mes_parametro_inicio, &dia_parametro_inicio);
    date_parsing(data_fim, &ano_parametro_fim, &mes_parametro_fim, &dia_parametro_fim);
    /*
    cout<<ano_parametro_inicio<<mes_parametro_inicio<<dia_parametro_inicio<<endl;
    cout<<ano_parametro_fim<<mes_parametro_fim<<dia_parametro_fim<<endl;
*/

    for (int i = 0; i < packs.size(); i++)
    {

        int ano_temp_inicio, ano_temp_fim, mes_temp_inicio, mes_temp_fim, dia_temp_inicio, dia_temp_fim;

        date_parsing(packs.at(i).data_inicio, &ano_temp_inicio, &mes_temp_inicio, &dia_temp_inicio);

        date_parsing(packs.at(i).data_fim, &ano_temp_fim, &mes_temp_fim, &dia_temp_fim);
        /*
        cout<<ano_temp_inicio<<mes_temp_inicio<<dia_temp_inicio<<endl;
        cout<<ano_temp_fim<<mes_temp_fim<<dia_temp_fim<<endl;
*/

        if ((ano_parametro_inicio >= ano_temp_inicio && ano_parametro_fim <= ano_temp_fim) && (mes_parametro_inicio >= mes_temp_inicio && mes_parametro_fim <= mes_temp_fim) &&
            (dia_parametro_inicio >= dia_temp_inicio && dia_parametro_fim <= dia_temp_fim))
        {
            cout << packs.at(i).id << endl;
            cout << packs.at(i).attraction_point << endl;
            cout << packs.at(i).data_inicio << endl;
            cout << packs.at(i).data_fim << endl;
            cout << packs.at(i).price_person << endl;
            cout << packs.at(i).lugares_inicial << endl;
            cout << packs.at(i).n_lugares_vendidos << endl;

            cout << "::::::::::" << endl;
            count++;
        }
    }

    if (count == 0)
    {
        cout << "No packs to display with on that period of time" << endl;
    }

    return;
}

int search_pack_by_ID(const vector<Pack> &packs, int id)
{

    for (int i = 0; i < packs.size(); i++)
    {

        if (abs(packs.at(i).id) == id)
        {
            return 1;
        }
    }

    return 0;
}


void display_packs_by_id(const vector <Pack> &packs,const vector <int> &indices){

    
    for(int i=0;i<indices.size();i++){


        int helper;

        helper=indices.at(i);

        if(helper>last_pack_id){

            //cout<<"Pack nao existente"<<endl;

            continue;

        }


        for(int j=0;j<packs.size();j++){


            if(abs(packs.at(j).id)==helper){

                helper=j;
                break;

            }

        }


        cout<< packs.at(helper).id<<endl;
        cout<< packs.at(helper).attraction_point<<endl;
        cout<< packs.at(helper).data_inicio<<endl;
        cout<< packs.at(helper).data_fim<<endl;
        cout<< packs.at(helper).price_person<<endl;
        cout<< packs.at(helper).lugares_inicial<<endl;
        cout<< packs.at(helper).n_lugares_vendidos<<endl;


    }



    return;
}



void create_new_pack(vector<Pack> &packs)
{

    Pack leitura_auxiliar;

    cout << "Introduzir ID" << endl;
    cin >> leitura_auxiliar.id;
    last_pack_id = leitura_auxiliar.id;

    cin.clear();
    cin.ignore(1000, '\n');

    cout << "Introduzir Destino-Locais turisticos separados por virgula Exemplo: Madeira-Funchal,Porto Santo" << endl;
    getline(cin, leitura_auxiliar.attraction_point);

    cout << "Data inicio no formato ano/mes/dia" << endl;
    getline(cin, leitura_auxiliar.data_inicio);

    cout << "Data fim no formato ano/mes/dia" << endl;
    getline(cin, leitura_auxiliar.data_fim);

    cout << "Introduzir o preco por pessoa" << endl;
    cin >> leitura_auxiliar.price_person;

    cout << "N de lugares disponiveis inicialmente" << endl;
    cin >> leitura_auxiliar.lugares_inicial;

    cout << "N de lugares ja vendidos" << endl;
    cin >> leitura_auxiliar.n_lugares_vendidos;

    packs.push_back(leitura_auxiliar);

    return;
}

void delete_pack(vector<Pack> &packs)
{

    for (int i = 0; i < packs.size(); i++)
    {

        system("clear");

        int is_this = 0;

        cout << endl;
        cout << packs.at(i).attraction_point << endl;
        cout << packs.at(i).data_inicio << endl;
        cout << packs.at(i).data_fim << endl;
        cout << packs.at(i).price_person << endl;
        cout << packs.at(i).lugares_inicial << endl;
        cout << packs.at(i).n_lugares_vendidos << endl;

        cout << "E este o pacote a apagar, se sim, digitar 1, se nao digitar outra tecla" << endl;

        cin >> is_this;

        if (is_this == 1)
        {

            packs.erase(packs.begin() + i);
        }
    }

    return;
}

void change_pack(vector<Pack> &packs)
{

    for (int i = 0; i < packs.size(); i++)
    {

        system("clear");

        int is_this = 0;

        cout << endl;
        cout << packs.at(i).id << endl;
        cout << packs.at(i).attraction_point << endl;
        cout << packs.at(i).data_inicio << endl;
        cout << packs.at(i).data_fim << endl;
        cout << packs.at(i).price_person << endl;
        cout << packs.at(i).lugares_inicial << endl;
        cout << packs.at(i).n_lugares_vendidos << endl;

        cout << "E este o client a alterar, se sim, digitar 1, se nao digitar outra tecla" << endl;

        cin >> is_this;
        cin.clear();
        cin.ignore(1000, '\n');

        if (is_this == 1)
        {

            cout << endl;
            cout << endl;

            cout << "Introduzir novo id" << endl;
            cin>> packs.at(i).id;

            cin.clear();
            cin.ignore(1000,'\n');

            cout << "Introduzir novo Attraction point, no formato Destino- Atracoes separadas por virgula. Exemplo: Madeira - Funchal, Porto Santo" << endl;
            getline(cin,packs.at(i).attraction_point);
            cout << "Introduzir nova data de inicio" << endl;
            getline(cin,packs.at(i).data_inicio);

            cout << "Introduzir nova data de fim" << endl;
            getline(cin,packs.at(i).data_fim);
            
            cout << "Inserir o preco por pessoa" << endl;
            cin>> packs.at(i).lugares_inicial;


            cout << "Inserir lugares inicialmente disponiveis" << endl;
            cin>> packs.at(i).lugares_inicial;

            cout<< "Inserir os lugares ja vendidos"<<endl;
            cin>>packs.at(i).n_lugares_vendidos;

            return;
        }
    }

    return;
}
