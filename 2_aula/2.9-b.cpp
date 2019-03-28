#include <iostream>
#include <iomanip>

using namespace std;


int main(){

    int leitura,maior=-1,menor=1000,comprimento=0,soma=0;
    double media=0;

    cout<<"Tamanho da sequencia"<<endl;

    cin>>comprimento;


    for(int i=0;i<comprimento;i++){

        cin>>leitura;

        if(leitura>maior){
            maior=leitura;
        }if(leitura<menor){
            menor=leitura;
        }

        soma+=leitura;
    }

    media=soma/comprimento;

    cin


    cout<<comprimento<<setw(3)<<soma<<setw(2)<<media<<setw(2)<<menor<<setw(2)<<maior<<endl;

    return 0;
}