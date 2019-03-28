#include <iostream>
#include <string>


using namespace std;


string Retira_Espacos_Inicio_FIM(string name){

    int i=0;
    int j=name.length()-1;

    cout << "Tamanho"<<j<<endl;
    
    string aux;
    
    while(name.at(i)!=' '){
        i++;
        cout <<i;

        
    }
/*
    while((name.at(j))!=' '){
        j--;
    }
*/

    //aux=name.substr(i,j);

    cout<<aux<<endl;

        

    return aux;
}



string normalizeName(string name){

    Retira_Espacos_Inicio_FIM(name);


    
}




int main(){

    string name;


    getline(cin,name);

    normalizeName(name);



    return 0;
}
