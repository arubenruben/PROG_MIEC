#include <iostream>
#include <string>

using namespace std;

void decompose(string compound){

    string substr;
    int j;
    substr.clear();

    for(int i=0;i<(compound.length());i++){

        if(compound.at(i)>='A'&&compound.at(i)<='Z'){
            
            if(substr.length()!=0){
                
                cout<<substr<<endl;

            }
            substr.clear();

            substr.push_back(compound.at(i));
            

        }

        if(compound.at(i)>='a'&&compound.at(i)<='z'){
            substr.push_back(compound.at(i));
        }

    }
    cout<<substr<<endl;



    return;

}


int main(){

    string compound;
    
    getline(cin,compound);

    decompose(compound);


    return 0;
}