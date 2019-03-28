#include <iostream>
#include <iomanip>
#include <cmath>

const int n=40;

using namespace std;


int main(){


    double soma=1;
    double fatorial=1;
    double x=1;

    for(int i=1;i<=n;i++){

        fatorial*=i;        
    
        if((i%2)==0){
            
            soma+=(x/fatorial);

        }else{

            soma-=(x/fatorial);
        }
        
        x=x*x;    
    }

    cout <<soma<<endl;






    return 0;
}

