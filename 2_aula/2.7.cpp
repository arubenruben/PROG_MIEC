#include <iostream>
#include <iomanip>
#include <cmath>

#define PI 3.1415

using namespace std;


int main(){

    double ang;
    double incremento,teto_maximo,teto_minimo;

    cout<<"Introduzir o teto minimo, maximo, e incremento"<<endl;

    cin>>teto_minimo>>teto_maximo>>incremento;


    cout<<"ang"<<setw(10)<<"sen"<<setw(10)<<"cos"<<setw(10)<<"tan"<<endl;
    


    for(int i=teto_minimo;i<=teto_maximo;i=i+incremento){
        ang=i*PI/180.0;

        cout<<i<<setw(5)<<setw(10)<<sin(ang)<<setw(10)<<cos(ang)<<setw(10)<<tan(ang)<<endl;
    }


    


    return 0;
}