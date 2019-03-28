#include <iostream>
#include <cmath>


using namespace std;

bool readFracc(int &numerator,int &denominator){

    int numerador,denominador;
    char separador;

    cin>>numerador>>separador>>denominador;

    if(separador=='/'&&denominador!=0){
        
        numerator=numerador;
        denominator=denominador;
        return true;
    }else{
        numerator=0;
        denominator=0;
        return false;
    }
    
}


void writeFracc(int numerator,int denominator){

    cout<<numerator<<"/"<<denominator<<endl;


}

int gcd(int a, int b)
{
    int q=0,r=0;

    do
    {
        q=b/a;
        r=b%a;

        b=a;

        if(r){
            a=r;
        }


    }while(r!=0);


    return a;
}



void soma_fracao(int numerator1, int denominator1,int numerator2,int denominator2,int &numerator, int &denominator){


    int mdc;

    numerator=(numerator1*denominator2)+(numerator2*denominator1);
    denominator=denominator1*denominator2;

    mdc=gcd(numerator,denominator);

    numerator/=mdc;
    denominator/=mdc;

    return;

}


void sub_fracao(int numerator1, int denominator1,int numerator2,int denominator2,int &numerator, int &denominator){


    int mdc;

    numerator=(numerator1*denominator2)-(numerator2*denominator1);
    denominator=denominator1*denominator2;

    mdc=gcd(numerator,denominator);

    numerator/=mdc;
    denominator/=mdc;

    return;

}


void mult_fracao(int numerator1, int denominator1,int numerator2,int denominator2,int &numerator, int &denominator){


    int mdc;

    numerator=numerator1*numerator2;
    denominator=denominator1*denominator2;

    mdc=gcd(numerator,denominator);

    numerator/=mdc;
    denominator/=mdc;

    return;

}


void div_fracao(int numerator1, int denominator1,int numerator2,int denominator2,int &numerator, int &denominator){


    int mdc;

    numerator=numerator1*denominator2;
    denominator=denominator1*numerator2;

    mdc=gcd(numerator,denominator);

    numerator/=mdc;
    denominator/=mdc;

    return;

}

int main(){

    int numerador,denominador,mdc;
    int numerador1,denominador1;
    int retorno_numerador,retorno_denominador;

    cout<<"Introduzir fracao"<<endl;

    if(readFracc(numerador,denominador)==true){

       writeFracc(numerador,denominador);

    }else{
        cout<<"erro"<<endl;
    }

    if(readFracc(numerador1,denominador1)==true){

       writeFracc(numerador1,denominador1);

    }else{
        cout<<"erro"<<endl;
    }

    mdc=gcd(numerador,denominador);

    numerador/=mdc;
    denominador/=mdc;


    //writeFracc(numerador,denominador);
    
    cout<<endl;

    soma_fracao(numerador,denominador,numerador1,denominador1,retorno_numerador,retorno_denominador);
    sub_fracao(numerador,denominador,numerador1,denominador1,retorno_numerador,retorno_denominador);
    mult_fracao(numerador,denominador,numerador1,denominador1,retorno_numerador,retorno_denominador);
    div_fracao(numerador,denominador,numerador1,denominador1,retorno_numerador,retorno_denominador);

    writeFracc(retorno_numerador,retorno_denominador);


    
    

    return 0;
}
