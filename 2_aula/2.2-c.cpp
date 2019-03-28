#include <iostream>
#include <cmath>

using namespace std;

int main(){

    double n1,n2,n3;
    double temp;
    double tolerancia=0.02;

    cout<<"N1, N2, N3"<<endl;

    cin>>n1>>n2>>n3;


    if(n1>n2){
        temp=n2;
        n2=n1;
        n1=temp;
    }
    if(n2>n3){
        temp=n3;
        n3=n2;
        n2=temp;
    }
    if(n1>n2){
        temp=n2;
        n2=n1;
        n1=temp;
    }


    cout<<n1 <<n2 << n3<<endl;

    if((n1+n2)>n3){ //se a soma do quadrado do maior, for igual a soma dos quadrados dos catetos,sim e triangulo
        cout<<"Sim é um triangulo";
    }else{
        cout<<"Nao é um triangulo";
    }
    
    

    


    return 0;
}