#include <iostream>
#include <cmath>

using namespace std;


int main(){

    unsigned int factorial=1;
    int n=100;

    double x;
    double somatorio=1;
    double anterior=-1000;
    double precisao;
    int i=1;

    cout<<"Introduza um valor de x"<<endl;

    cin>>x;
    cout<<"Precisao"<<endl;
    cin>>precisao;

    while(fabs(somatorio-anterior)>precisao){


        factorial*=i;
        
        anterior=somatorio;

        if((i%2)!=0){

            somatorio-=(x/(double)factorial);

        }else{

            somatorio+=(x/(double)factorial);
        }

        x*=x;
        i++;
    }



    cout<<somatorio<<endl;




    return 0;
}