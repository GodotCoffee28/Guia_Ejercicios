/*Haga una función que tome como entrada un arreglo de enteros A y un
número K y determine si existen dos valores de A que sumados sean
iguales a K. Por ejemplo, si A = {4,−1, 6, 8, 10, 3} y K = 2, la función
debe retornar verdadero ya que −1 + 3 = 2.*/

#include<iostream>
#include <cstdlib> 
#include <ctime>
using namespace std;   

void LlenarArregloeglo(int *Arreglo, int Tamaño){
    srand(time(0));
    int Min = -50;
    int Max = 50;
    int Num;

    for(int i = 0; i < Tamaño; i++){
        Num = rand() % (Max - Min + 1) + Min;
        Arreglo[i] = Num;
    }
}

void MostrarArregloeglo(int *Arreglo, int Tamaño, char letra = ' '){
    cout<<"Elementos del Arreglo"<<letra<<":";
    for(int i = 0; i < Tamaño; i++){
        cout<<" "<<Arreglo[i]<<" ";
    }
    cout<<endl;
}



bool BuscarK(int *Arreglo, int Tamaño, int K){

    for(int i=0; i < Tamaño; i++){

        for(int j = 0; j < Tamaño; j++){


            if(i == j) continue;

            int SumaActual = Arreglo[i] + Arreglo[j];

            if(SumaActual == K){

                cout<<"La suma es: "<<Arreglo[i]<<" + "<<Arreglo[j]<<endl;

                return true;
            }
        }
    }
    return false;
}

int main(){

    cout<<"Indiqueme el tamaño de su arreglo A: ";
    int TamañoA;
    cin>>TamañoA;

    int *ArregloA = new int[TamañoA];
    LlenarArregloeglo(ArregloA, TamañoA);
    cout<<"Indique su numero K: "; 
    int K;
    cin>>K;
    MostrarArregloeglo(ArregloA, TamañoA);
    bool  SeEncuentraK = BuscarK(ArregloA, TamañoA, K);

    if(SeEncuentraK){
        cout<<"Se ha encontrado la suma en el arreglo"<<endl;
    }else{
        cout<<"No se ha encontrado la suma en el arreglo"<<endl;

    }
    delete[] ArregloA;
    return 0;
}