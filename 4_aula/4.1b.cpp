#include <iostream>
#include <string>


#define CHAR_MAX 100

using namespace std;


bool isHydroxide(string compound){
    
    if(compound.size()==0){
        return false;
    }else{
        
        if(compound.at(compound.length()-1)=='H'&&compound.at(compound.length()-2)=='O'){
            return true;
        }

    }


    return false;

}



int main(){

    string str;

    cout<<"Introduzir componente"<<endl;

    getline(cin,str);

    if(isHydroxide(str)==true){
        cout<<"E hidroxido"<<endl;
    }else{
        cout<<"Nao e hidroxido"<<endl;
    }
    









    return 0;
}