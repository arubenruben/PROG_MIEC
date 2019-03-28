#include <iostream>
#include <cmath>

using namespace std;


int main(){

    int x1,x2,x3;
    int y1,y2,y3;
    double semi=0,lado1,lado2,lado3,area;

    cout <<"Inserir valor de x1"<<endl;
    cin >> x1;

    cout <<"Inserir valor de y1"<<endl;
    cin >> y1;

    cout <<"Inserir valor de x2"<<endl;
    cin >> x2;

    cout <<"Inserir valor de y2"<<endl;
    cin >> y2;

    cout <<"Inserir valor de x3"<<endl;
    cin >> x3;

    cout <<"Inserir valor de y3"<<endl;
    cin >> y3;

////////////

    lado1=sqrt(pow((x2-x1),2) + pow((y2-y1),2));
    
    lado2=sqrt(pow((x3-x1),2) + pow((y3-y1),2));

    lado3=sqrt(pow((x3-x2),2) + pow((y3-y2),2));

    semi=(lado1+lado2+lado3)/2.0;

    area=sqrt(semi*(semi-lado1)*(semi-lado2)*(semi-lado3));

    cout<<"Area e "<<area<<endl; 




    return 0;
}