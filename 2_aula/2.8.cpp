#include <iostream>
#include <cmath>

using namespace std;


int main(){

    int anos;
    double quantia,taxa_juro;
    

    cout<<"Introduzir o numero de anos, a quantia e a taxa de juro"<<endl;

    cin>>anos>>quantia>>taxa_juro;

    taxa_juro=(taxa_juro/100.0);

    for(int i=1;i<=anos;i++){

        cout<<i<<" "<<quantia<<" "<<taxa_juro<<endl;

        quantia=quantia+(quantia*taxa_juro);
    }
    

    cout<<"Quantia: "<<quantia<<endl;

    return 0;
}