#include <iostream>
#include <string>


using namespace std;


bool sequenceSearch(string s,int nc,char c){

    //nc tem o n
    
    int contador=0;
    int pos=0;
    
    
    for(int i=0;i<(s.length());i++){


        if(s.at(i)==c){
            contador ++;
        }else{
            contador = 0;
        }
    }

    if(contador==nc){
        return true;
    }
    
    return false;

}


int main(){

    int nc;
    char c;
    string leitura;
    
    cout <<"Introduz string, n vezes, carater"<<endl;
    
    
    getline(cin,leitura);

    cin>>nc>>c;

    if(sequenceSearch(leitura,nc,c)==true){
        cout<<"Existe"<<endl;
    }else{
        cout<<"Nao existe"<<endl;
    }

    
    return 0;
}