#include <iostream>
#include <cmath>

using namespace std;

//-b+-sqrt(b^2.0-4*(a*c))

int main(){

    double a,b,c;
    double raiz_numerador;
    double zero;
    cout<< "Introduza os valores de a,b e c"<<endl;
    cin >>a>>b>>c;


    raiz_numerador=pow(b,2)-4*a*c;

    if(raiz_numerador>0){
        cout<< "Raiz real";
        raiz_numerador=sqrt(raiz_numerador);

        cout<<(-b+raiz_numerador)/(2.0*a)<<endl<<(-b-raiz_numerador)/(2.0*a);
    }else{
        
        double parte_real,parte_imaginaria;

        parte_real=-b/(2.0*a);
        
        raiz_numerador*=-1;

        raiz_numerador=sqrt(raiz_numerador);
        
        
        parte_imaginaria=raiz_numerador/(2.0*a);

        cout<<parte_real<<" "<<parte_imaginaria<<endl;
        cout<<parte_real<<" "<<-parte_imaginaria<<endl;
    }
    





    return 0;
}