#include <iostream>
#include <cmath>


using namespace std;

double round(double x, unsigned n){

    return floor((x*pow(10,n)+0.5))/(pow(10,n));
}



int main(){


    double x=0;
    unsigned n;

    cout<<"x,n"<<endl;

    cin>>x>>n;

    x=round(x,n);

    cout<<x<<endl;

    return 0;
}