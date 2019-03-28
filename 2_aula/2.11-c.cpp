#include <iostream>
#include <cmath>

using namespace std;


int main(){

    unsigned int factorial=1;
    int n=100;

    double x;
    double somatorio=1;
    double anterior=-1000;
    cout<<"Introduza um valor de x"<<endl;

    cin>>x;


  for(int i=1;i<=n;i++){

        factorial*=i;

        if((i%2)!=0){

            somatorio-=(x/(double)factorial);

        }else{

            somatorio+=(x/(double)factorial);
        }

        x*=x;
    }



    cout<<somatorio<<endl;




    return 0;
}