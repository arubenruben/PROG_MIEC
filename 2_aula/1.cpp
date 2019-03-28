#include <iostream>

using namespace std;


int main(){
    double a,b,c,d,e,f;
    double x,y;
    cout<< "Insira valor de a b c d e f"<<endl;
    
    cin>>a>>b>>c>>d>>e>>f;

    if(((c*e-b*f)!=0 && (a*e-b*d)==0)||((a*f-c*d)!=0 && (a*e-b*d)==0)){
        cout<<"Sistema impossivel"<<endl;
    }else if((c*e-b*f)==0 && (a*e-b*d)==0){
        cout<<"Indeterminado em X";
        y=(a*f-c*d)/(a*e-b*d);
        cout<<"Valor de y "<<y;    
    }else if((a*f-c*d)==0 && (a*e-b*d)==0){
        cout<<"Indeterminado em Y";
        x=(c*e-b*f)/(a*e-b*d);
        cout<<"Valor de x "<<x;    
    }else{
        x=(c*e-b*f)/(a*e-b*d);
        y=(a*f-c*d)/(a*e-b*d);
        cout<<"Valor de x "<<x;    
        cout<<"Valor de y "<<y;    
    }

    return 0;
}