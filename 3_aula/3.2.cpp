#include <iostream>
#include <cmath>


using namespace std;


int is_prime(int x){

    for(int i=2;i<=sqrt(x);i++){

        if(x%i==0){
            return 1;
        }

    }

    return 0;
}


int main(){


    int n;

    cout<<"Introduza um numero"<<endl;

    cin>>n;

    if(is_prime(n)==0){

        cout<<"E primo"<<endl;

    }else{

        cout<<"Nao e primo"<<endl;
    }

    return 0;
}