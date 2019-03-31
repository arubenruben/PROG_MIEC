#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <cmath>
#include <cstring>
#include <stdlib.h>


using namespace std;



string read_address(ifstream &file_read_obj){

    string leitura_aux;
    string morada_completa;
    
    string erro="erro";

    if(getline(file_read_obj,leitura_aux,'/')){
        morada_completa=leitura_aux;
    }else{
        cout<<"Leitura invalida na agencia"<<endl;
        return erro;
        
    }


    
    if(getline(file_read_obj,leitura_aux,'/')){
        
        if(atoi(leitura_aux.c_str())){
            morada_completa+='/';
            morada_completa+=leitura_aux;
            morada_completa+='/';
        }
        
    }else{
        cout<<"Leitura invalida na agencia1"<<endl;
        return erro;
        
    }


    if(getline(file_read_obj,leitura_aux,'/')){
        morada_completa+=leitura_aux;
        morada_completa+='/';

    }else{
        cout<<"Leitura invalida na agencia"<<endl;
        return erro;
        
    }


    //zip-code

    if(getline(file_read_obj,leitura_aux,'/')){
        morada_completa += leitura_aux;
        morada_completa += '/';
    }else{
        cout<<"Leitura invalida na agencia"<<endl;
        return erro;
        
    }
    
    //Localidade

    if(getline(file_read_obj,leitura_aux)){
        morada_completa += leitura_aux;
    }else{
        cout<<"Leitura invalida na agencia"<<endl;
        return erro;
    }

    return morada_completa;




}

