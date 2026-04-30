#include<iostream>
using namespace std;

/*Haga un algoritmo que tome como 
entrada 2 números distintos e imprima
el segundo número mayor*/

int main(){

    //1 , 2 Primer mayor 2, Segundo mayor 1. 1 es menor o el segundo meno

    cout<<"Ingresen 2 valores distintos entre si"<<endl;

    int v1, v2;
    cin>> v1>> v2;
    if(v1 == v2){
        cout<<"Error son iguales, capo";
        return 0;
    }   
    // v1 mayor que v2 , v2 menor que v1
    if( v1 > v2){
        cout<<"Primer Mayor:" <<v1<<" Segundo mayor:"<<v2<<endl;
    }else{ // v2 > v1
        // v1 es menor que v2 entonces v2 es mayor que v1
        cout<<"Primer Mayor:" <<v2<<" Segundo mayor:"<<v1<<endl;
    }

    return 0;
}