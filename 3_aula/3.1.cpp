#include <iostream>
#include <cmath>


using namespace std;

double distance(double x1,double y1,double x2,double y2);

double area(double x1,double y1,double x2,double y2, double x3, double y3){

    double perimetro=0;

    double lado1,lado2,lado3;
    
    lado1=distance(x1,y1,x2,y2);
    
    lado3=distance(x1,y1,x3,y3);
    
    lado2=distance(x2,y2,x3,y3);

    perimetro=lado1+lado2+lado3;

    perimetro/=2.0;


    return sqrt( perimetro*(perimetro-lado1)*(perimetro-lado2)*(perimetro-lado3) );
}


double distance(double x1,double y1,double x2,double y2){


    return sqrt(   pow((x2-x1),2)+ pow((y2-y1),2)      );


}


int main(){


    double x1,y1,x2,y2,x3,y3;
    double area_value;

    cout<<"x1,y1,x2,y2,x3,y3"<<endl;

    cin>>x1>>y1>>x2>>y2>>x3>>y3;

    area_value=area(x1,y1,x2,y2,x3,y3);

    cout<<area_value<<endl;

    
    return 0;
}