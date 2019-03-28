#include <iostream>

using namespace std;

int main(){


    int h1,h2,min1,min2,s1,s2;
    int hf=0,mf=0,sf=0;
    int dias=0;


    cout<< "Inserir hora, minuto, segundos do primeiro tempo\n";
    cin>>h1>>min1>>s1;

    cout<< "Inserir hora, minuto, segundos do segundo tempo\n";
    cin>>h2>>min2>>s2;
    
    sf=(s1+s2)%60;

    if((s1+s2)>60){
        mf++;
    }
    
    if((mf+min1+min2)>60){
        hf++;
    }

    mf=(mf+min1+min2)%60;


    if(h1+h2+hf>24){
        dias++;
    }
    hf=(h1+h2+hf)%24;

    if(dias!=0){

        cout<<dias <<"Dias "<<hf <<"Hora final "<<mf <<"Minutos "<<sf << "Segundos ";
        
    }else{
        cout<<hf<<"Hora final "<<mf<<"Minutos "<<sf<< "Segundos ";
    }
    

    


    return 0;
}   