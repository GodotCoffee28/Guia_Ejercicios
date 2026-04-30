/*3. Escriba un algoritmo que lea un número de cuatro dígitos y muestre en
pantalla el número escrito en reverso. Por ejemplo, si el número es 4678, la
salida debería ser 8764*/
// 1234 -> 1 2 3 4
// 0000 + 4 * 10^3 

#include<iostream>
using namespace std;



int main(){
    int Num = 0;
    cin>>Num;
    //Asumimos que es de 4 digitos
    int N1=0,N2=0,N3=0,N4=0;
    //Ej 1234
    //N1= 1, N2=2, N3=3, N4 = 4
    
    N1 = Num / 1000; // -> 1234 / 1000  = 1 
    N2 = (Num / 100) % 10; // -> 1234 / 100 = 12 %  10 = 2
    N3 = (Num / 10) % 10; 
    N4 = Num % 10; 

    //Ya tengo las digitos del numero original "picados"

    int Num_Inverso = 0;

    //0000 ; 1 2 3 4
    Num_Inverso = Num_Inverso + N1;
    Num_Inverso = Num_Inverso + N2 * 10;
    Num_Inverso = Num_Inverso + N3 * 100;
    Num_Inverso = Num_Inverso + N4 * 1000;


    cout<<Num_Inverso;

    return 0;
}