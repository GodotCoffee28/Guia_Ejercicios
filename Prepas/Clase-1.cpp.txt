#include<iostream>
using namespace std;
/*Dadas las ecuaciones de dos rectas no paralelas y1 = m1x+b1 y y2 = m2x+b2,
escribir un algoritmo que calcule su punto de intersección.2*/

//  m1 * x - m2 * x = y2 - y1
//x = (b2 - b1) / (m1 - m2)
int main(){

int m1, m2, b1, b2, x;

cin>>m1>>m2>>b1>>b2;
cout<<endl;
x =  (b2-b1) / (m1 - m2);
cout<<x;

    return 0;
}