/*5. Escriba un algoritmo que transforme un número binario de cuatro bits a
un número decimal.*/

//1010 -> 10
//2^3*1 + 2^2*0 + 2^1*1 + 2^0*0  = un numero decimal
//

#include<iostream>
#include<math.h>
using namespace std;


int main(){

    int Bit =0;
    cin>>Bit;

    int N1=0,N2=0,N3=0,N4=0;
    N1 = Bit / 1000; // -> 1234 / 1000  = 1  Bit mas significativo
    N2 = (Bit / 100) % 10; // -> 1234 / 100 = 12 %  10 = 2
    N3 = (Bit / 10) % 10; 
    N4 = Bit % 10; 

    int Decimal = 0;

    Decimal = pow(2,0) * N4 + pow(2,1) * N3 + pow(2,2) * N2 + pow(2,3) * N1;

    cout<<Decimal;

    return 0;
}
