#include <iostream>

using namespace std;

double media(int first,int sec, int third){

    return (first+sec+third)/3.0;
}


int main(){

    int first,sec,third;
    double mean;

    cout<<"insira o primeiro numero";
    cin>>first;
    cout<<"insira o segundo numero";
    cin>>sec;
    cout<<"insira o terceiro numero";
    cin>>third;
    cout<<endl;

    mean=media(first,sec,third);

    cout<<"media"<<mean<<endl<<"A-media"<<(first-mean)<<endl<<"b-media"<<(sec-mean)<<endl<<"c-media"<<(third-mean)<<endl;
    

    return 0;
}