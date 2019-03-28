#include <iostream>
#include <iomanip>
#include <cmath>



using namespace std;


int main(){

    int i=1,numero,tamanho=0, j;
    double aux;
    int algarismo_mais_significativo,algarismo_menos_significativo;
    int capicua=1;

    cin>>numero;
    

    while((numero/i)!=0){

        i*=10;
        tamanho++;

    }
    j=tamanho;
    
    for(i=1;i<=tamanho/2;i++){
        
        aux=(double)numero/10.0;

        aux=aux-trunc(aux);
        aux*=10;
        algarismo_menos_significativo=round(aux);

        cout<<algarismo_menos_significativo<<endl;

        algarismo_mais_significativo=trunc(numero/pow(10,j-i));
        
        cout<<algarismo_mais_significativo<<endl;
        
    if(algarismo_mais_significativo!=algarismo_menos_significativo){
        cout<<"Nao e capicua"<<endl;
        capicua=0;
        break;
    }

        numero=numero-(algarismo_mais_significativo*pow(10,j-i));
        numero=numero/10;
        
        
        j--;
    }


    if(capicua==1){
        cout<<"E capicua"<<endl;
    }

    return 0;
}