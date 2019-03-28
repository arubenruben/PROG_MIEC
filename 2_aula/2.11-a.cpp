#include <iostream>
#include <iomanip>
#include <cmath>

const int n=100;

using namespace std;


int main(){


    double soma=4;
    double j=3;

    for(int i=0;i<n;i++){

        if(i%2==0){
            soma=soma-(4.0/j);
        }else{
            soma=soma+(4.0/j);
        }

        j=j+2;

    }

    cout <<soma<<endl;






    return 0;
}

