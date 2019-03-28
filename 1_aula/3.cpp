#include <iostream>
#include <cmath>
using namespace std;

const double PI=3.1415926535;

int main(){
    double densidade,massa,raio;
    
    cout<< "insira em Kg/m^3, a densidade";
    cin >>densidade;

    cout<< "insira o raio em metros"<<endl;
    cin>> raio;
    
    cout<<"A massa da esfera é:"<<endl<<(4/3.0)*(PI*densidade*pow(raio,3));






}