#include <iostream>
#include <cmath>

using namespace std;

int main(){

    double peso;
    double preco=0;

    cout<<"Introduza o peso, em gramas"<<endl;

    cin>>peso;

    if(peso<500){
        preco=5;

    }else if(peso<1000){
        preco=5+((int)(peso-500)/100)*1.5;
        cout<<preco<<endl;
    }else{
        preco=12.5+((int)(peso-1000)/250)*5;
    }

    cout<< preco<<endl;


    return 0;
}