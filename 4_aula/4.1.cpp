#include <iostream>
#include <string.h>
#include <string>

#define CHAR_MAX 100

using namespace std;


bool isHydroxide(char compound[]){

    int tamanho=strlen(compound);
    cout<<tamanho<<endl;

    if(tamanho==0){
        return false;
    }else{

        if(compound[tamanho-1]=='H'&&compound[tamanho-2]=='O'){
            return true;
        }

    }



    return false;

}



int main(){

    char str[CHAR_MAX];

    cout<<"Introduzir componente"<<endl;

    cin>>str;

    if(isHydroxide(str)==true){
        cout<<"E hidroxido"<<endl;
    }else{
        cout<<"Nao e hidroxido"<<endl;
    }
    









    return 0;
}