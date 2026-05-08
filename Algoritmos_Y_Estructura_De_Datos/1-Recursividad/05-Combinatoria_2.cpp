#include<iostream>
#include<math.h>

using namespace std;

/*Construya una función recursiva que calcule el valor de la combinatoria de 2 números enteros.*/

int factorial(int n);
int CombinatoriaMatematica(int n, int m);
int CombinatoriaRecursiva(int n, int m);


int main(){
int n = 0, m = 0;
do{
cout<<"Introduzca su numero n positivo : "; cin>>n; cout<<endl;
if(n<0){
    cout<<"ERROR, su numero tiene que ser positivo"<<endl;
}
}while(n<0);
do{
cout<<"Introduzca su numero m positivo y menor que "<<n<<": "; cin>>m; cout<<endl;
if(m<0||m>n){
    cout<<"ERROR, su numero tiene que ser positivo y menor que "<<n<<endl;
}
}while (m<0||m>n);

cout<<"La cantidad de combinaciones posibles en "<<n<<" "<<"elementos agrupados de "<<m<<" en "<<m<<" es: "<<CombinatoriaRecursiva(n,m);

    return 0;
}

int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}

int CombinatoriaMatematica(int n, int m){
    return (factorial(n)/(factorial(n-m)*factorial(m)));
}

int CombinatoriaRecursiva(int n, int m){
    if(m == 0 || m == n) return 1;
    return CombinatoriaRecursiva(n-1, m-1) + CombinatoriaRecursiva(n-1,m);
}