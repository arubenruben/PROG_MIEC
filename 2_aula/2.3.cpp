#include <iostream>
#include <cmath>

using namespace std;

int main(){

    double n1,n2;
    char operador;

    cout<<"Introduza o n1, n2 e operador"<<endl;
    
    cin>> n1>>n2>>operador;
    if(operador=='+'){
        cout<<n1+n2;
    }else if(operador=='-'){
        cout<<n1-n2;
    }else if(operador=='*'){
        cout<<n1*n2;
    }else if(operador=='/'){
        cout<<n1/n2;
    }


    return 0;
}
