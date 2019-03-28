#include <iostream>
#include <cmath>

using namespace std;


int main(){


    int n;
    int multiplo=0;
    int shutdown=0;

    cout<<"Introduza um numero inteiro";

    cin>>n;
    
    if(n<2){
        
        cout<<"Nao e primo"<<endl;

        return 0;
    }


    for(int i=2;i<=sqrt(n);i++){
        multiplo=0;

        for(int j=1;multiplo<n;j++){
            
            multiplo=i*j;

            if(multiplo==n){
                shutdown=1;
                break;
            }


        }

        if (shutdown == 1)
        {
            break;
        }

    }

    if(shutdown==1){
        cout<<"Nao e primo"<<endl;
    }else{
        cout<<"E primo"<<endl;
    }

    return 0;
}