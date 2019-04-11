#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
#include <cstring>
#include <vector>
#include <stdlib.h>

using namespace std;

string read_address(ifstream &file_read_obj)
{

    string leitura_aux;
    string morada_completa;

    string erro = "erro";

    if (getline(file_read_obj, leitura_aux, '/'))
    {
        morada_completa = leitura_aux;
    }
    else
    {
        cout << "Leitura invalida na agencia" << endl;
        return erro;
    }

    if (getline(file_read_obj, leitura_aux, '/'))
    {

        if (atoi(leitura_aux.c_str()))
        {
            morada_completa += '/';
            morada_completa += leitura_aux;
            morada_completa += '/';
        }
    }
    else
    {
        cout << "Leitura invalida na agencia1" << endl;
        return erro;
    }

    if (getline(file_read_obj, leitura_aux, '/'))
    {
        morada_completa += leitura_aux;
        morada_completa += '/';
    }
    else
    {
        cout << "Leitura invalida na agencia" << endl;
        return erro;
    }

    //zip-code

    if (getline(file_read_obj, leitura_aux, '/'))
    {
        morada_completa += leitura_aux;
        morada_completa += '/';
    }
    else
    {
        cout << "Leitura invalida na agencia" << endl;
        return erro;
    }

    //Localidade

    if (getline(file_read_obj, leitura_aux))
    {
        morada_completa += leitura_aux;
    }
    else
    {
        cout << "Leitura invalida na agencia" << endl;
        return erro;
    }

    return morada_completa;
}

void date_parsing(string date, int *ano, int *mes, int *dia)
{

    char str_aux[50];
    size_t pointer = 0;
    size_t pos_barra;

    pos_barra = date.find('/', pointer);

    date.copy(str_aux, pos_barra - pointer, pointer);

    *ano = atoi(str_aux);

    pointer = pos_barra + 1;

    pos_barra = date.find('/', pointer);

    date.copy(str_aux, pos_barra - pointer, pointer);

    str_aux[2] = '\0'; //tem de ser assim

    *mes = atoi(str_aux);

    pointer = pos_barra + 1;

    pos_barra = (date.length());

    date.copy(str_aux, pos_barra - pointer, pointer);

    str_aux[2] = '\0';

    *dia = atoi(str_aux);

    return;
}

void id_packs_client_bought(string str_to_transform, vector<int> &id_packs_bought)
{

    char str_aux[100];
    int pack_id;
    size_t pointer = 0;
    size_t pos_semicolon;

    
    pos_semicolon=str_to_transform.find(';',pointer);

    while(pos_semicolon!=string::npos){
        
        pos_semicolon=str_to_transform.find(';',pointer);

        str_to_transform.copy(str_aux, pos_semicolon - pointer, pointer);

        pack_id = atoi(str_aux);

        pointer=pos_semicolon+1;

        id_packs_bought.push_back(pack_id);

        for(int j=0;j<99;j++){

            str_aux[j]='\0';

        }
    }



    return;
}