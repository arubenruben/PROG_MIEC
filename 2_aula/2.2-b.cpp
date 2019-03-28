#include <iostream>

using namespace std;

int main(){

    double n1,n2,n3;
    double temp;

    cout<<"N1, N2, N3"<<endl;

    cin>>n1>>n2>>n3;


    if(n1>n2){
        temp=n2;
        n2=n1;
        n1=temp;
    }
    if(n2>n3){
        temp=n3;
        n3=n2;
        n2=temp;
    }
    if(n1>n2){
        temp=n2;
        n2=n1;
        n1=temp;
    }


    cout<<n1 <<n2 << n3<<endl;

    
    
    

    


    return 0;
}