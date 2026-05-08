#include<iostream>
using namespace std;

/*Escriba un algoritmo que imprima por pantalla en borde de un cuadrado de
lados de tamaño N. Por ejemplo, si N = 5, el algoritmo debería imprimir:*/


int main(){
    int N;
    cout<<"Ingrese su N:"<<endl;
    cin>>N;
    cout<<endl;
    for(int i=0; i < N; i++){
        for(int j=0; j<N; j++){
            if( i == 0 || i == N - 1  || j == 0 || j == N-1){
                cout<<"X";
            }else{
                cout<<" ";
            }
        }
        cout<<endl;
    }

    return 0;
}