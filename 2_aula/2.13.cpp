#include <iostream>


using namespace std;




int main(){


    int numero;
    int aux=numero;
    int soma=0;
    
    cout<<"Insira o numero";

    cin>>numero;


    for(int i=2;i<=numero;i++){
        
            
        while((numero%i)==0){
            cout<<i<<"x";
            
            numero/=i;
        }



    }






    return 0;
}