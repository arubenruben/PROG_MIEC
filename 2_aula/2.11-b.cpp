#include <iostream>
#include <iomanip>
#include <cmath>

const int n=100;

using namespace std;


int main(){


    double soma=1;
    double j=1;

    for(int i=1;i<=n;i++){

        j=i*j;
        soma+=(1/j);
        
    }

    cout <<soma<<endl;






    return 0;
}

