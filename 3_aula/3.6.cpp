#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;


bool bissexto(int ano){

    if((ano%4)==0){

        if((ano%100)!=0){
            
            return true;

        }else if((ano%400)==0){
            return true;
        }

    }

    return false;
}



int n_dias_mes(int mes,int ano){

    if(mes<=0||mes>12){

        return -1;
    }
    
    if(mes==1||mes==3||mes==5||mes==7||mes==8||mes==10||mes==12){
        
        return 31;

    }else if(mes==2){
        if(bissexto(ano)==true){
            return 28;
        }else{
            return 27;
        }
    }

    return 30;
}


int valor_c(int mes,int is_bissexto){

    if(is_bissexto==1){

        if(mes==1){
            return 6;
        }
        if(mes==2){
            return 2;
        }
        if(mes==3){
            return 3;
        }
        if(mes==4){
            return 6;
        }
        if(mes==5){
            return 1;
        }
        if(mes==6){
            return 4;
        }
        if(mes==7){
            return 6;
        }
        if(mes==8){
            return 2;
        }
        if(mes==9){
            return 5;
        }
        if(mes==10){
            return 0;
        }
        if(mes==11){
            return 3;
        }
        if(mes==12){
            return 5;
        }
    }else{

        if(mes==1){
            return 0;
        }
        if(mes==2){
            return 3;
        }
        if(mes==3){
            return 3;
        }
        if(mes==4){
            return 6;
        }
        if(mes==5){
            return 1;
        }
        if(mes==6){
            return 4;
        }
        if(mes==7){
            return 6;
        }
        if(mes==8){
            return 2;
        }
        if(mes==9){
            return 5;
        }
        if(mes==10){
            return 0;
        }
        if(mes==11){
            return 3;
        }
        if(mes==12){
            return 5;
        }

    }

    return -1;
}


int dois_ultimos_dig(int ano){

    double temp;
    int parte_inteira;

    temp=(double)ano/100.0;


    parte_inteira=trunc(temp);

    temp-=parte_inteira;

    parte_inteira=temp*100;


    return parte_inteira;

}

int dois_primeiros_dig(int ano){


    int size=0;
    int aux_ano=ano;

    while((ano)!=0){
        ano/=10;
        size++;

    }
    



    return aux_ano/pow(10,size-2);
    
}


int dia_semana(int dia, int mes, int ano){


    int aux= ((5*dois_ultimos_dig(ano))/4.0)+valor_c(mes,(int)bissexto(ano))+dia-2*(dois_primeiros_dig(ano)%4)+7 ;
    aux=aux%7;

    return aux;


}

int main(){


    int ano,mes,dia;

    cout<<"Introduza o ano"<<endl;

    cin>>ano;
    


    if(bissexto(ano)==true){

        cout<<"E Bissexto"<<endl;

    }else{
        cout<<"Nao e bissexto"<<endl;
    }

    cout<<"Introduza o mes"<<endl;

    cin>>mes;

    cout<<"Introduza o dia"<<endl;

    cin>>dia;

    cout<<dois_ultimos_dig(ano)<<endl;

    cout<<dois_primeiros_dig(ano)<<endl;

    cout<<dia_semana(dia,mes,ano)<<endl;


    




    return 0;
}