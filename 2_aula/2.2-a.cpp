#include <iostream>

using namespace std;

int main(){

    double n1,n2,n3;
    double maior,menor;

    cout<<"N1, N2, N3"<<endl;

    cin>>n1>>n2>>n3;


    if(n1<n2){
        maior=n2;
        menor=n1;
    }else{
        maior=n1;
        menor=n2;
    }

    if(maior<n3){
        maior=n3;
    }else if(menor>n3){
        menor=n3;
    }

    cout<<"Maior: "<<maior <<"Menor: "<< menor;



    return 0;
}