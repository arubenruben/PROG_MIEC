#include <iostream>

using namespace std;


int main(){
    double a,b,c,d,e,f;
    double x,y;
    cout<< "Insira valor de a b c d e f"<<endl;
    cin>>a>>b>>c>>d>>e>>f;

    x=(c*e-b*f)/(a*e-b*d);
    y=(a*f-c*d)/(a*e-b*d);
    cout<< "Valor de x"<<x<<"Valor de y \n"<<y;

    return 0;
}