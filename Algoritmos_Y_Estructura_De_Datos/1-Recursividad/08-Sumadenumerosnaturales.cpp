#include<iostream>
/*Escriba un algoritmo recursivo que halle la suma de los primeros N números naturales.*/
using namespace std;
int SumaDeNaturales(int n, int sum=0);
int main(){
    int n;

    cout<<"Suma de numeros naturales desde 0 hasta: ";cin>>n;
    cout<<" es: "<<SumaDeNaturales(n);
    return 0;
}

int SumaDeNaturales(int n, int sum){
    if(n==0) return sum;
    return SumaDeNaturales(n-1, sum+n);
}
