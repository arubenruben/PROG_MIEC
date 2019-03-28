#include <iostream>
#include <iomanip>

using namespace std;


int main(){

    int leitura,maior=-1,menor=1000,comprimento=0,soma=0;
    double media=0;


    while (cin>>leitura){

        comprimento++;

        if(leitura>maior){
            maior=leitura;
        }if(leitura<menor){
            menor=leitura;
        }

        soma+=leitura;
    }

    media=soma/comprimento;


    cout<<comprimento<<setw(2)<<soma<<setw(2)<<media<<setw(2)<<menor<<setw(2)<<maior;

    return 0;
}