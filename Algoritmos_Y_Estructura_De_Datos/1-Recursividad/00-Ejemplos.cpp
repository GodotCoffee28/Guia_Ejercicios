#include<iostream>
using namespace std;


int sumaDe_n(int n, int resultado){ //Recursiva
    if(n >= 0){
        return resultado + n + sumaDe_n(n-1, resultado);
    }
    return resultado;
}

int SumaMatematica(int n){ //100000000000000000000000
    return (n*(n+1))/2;
}

int SumaM(int N ){ //Iteratuva
    int suma = 0;
    for(int i = 1; i <= N; i++){ //i= 1,2,3,...,N
        suma+=i;
    }
    return suma;
}

int suma(int n){
    if(n==0){
        return 0;
    }
    else{
        return (n+suma(n-1));
    }
}


int main(){


    cout<<sumaDe_n(5,0)<<"\n";
    cout<<SumaM(5)<<"\n";
    cout<<SumaMatematica(5)<<"\n";


    return 0;
}