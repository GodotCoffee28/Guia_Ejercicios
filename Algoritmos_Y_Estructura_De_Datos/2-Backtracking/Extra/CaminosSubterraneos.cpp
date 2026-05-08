#include<iostream> //stdlib, fstream, string, iostream, math.h o csmath, string, vector, chrono.
#include<fstream>
#include<string>
#include<vector>
#include<math.h>
#include<chrono>
using namespace std;
using namespace chrono;


void LnicializarLaberinto(int**& Laberinto, int N){
 // Un arreglo de punteros, representa a las filas
Laberinto = new int*[N]; //asignar la memoria para las filas
for(int i=0; i<N; i++) Laberinto[i] = new int[N]; //Ajhora para cada fila, se asigna memoria para cada columna

//Ejecute sus mediciones en matrices con N = 10, N = 20 y N = 50.

}

void LorrarLaberinto(int**& Laberinto, int N){
for(int i=0; i<N;i++) delete[] Laberinto[i], Laberinto[i]=nullptr; //liberar memoria de cada fila
delete[] Laberinto; //liberar la memoria del arreglo de punteros a filas
Laberinto=nullptr; //Opcional pero buena practica
}


int main(){
auto startTime= high_resolution_clock::now();


const int N=50; //tamaño fijo
int** Laberinto=nullptr;


LnicializarLaberinto(Laberinto, N);

if(Laberinto!=nullptr){
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            cout<<Laberinto[i][j]<<" ";
        }
        cout<<endl;
    }
}





LorrarLaberinto(Laberinto,N);
auto endtime=high_resolution_clock::now();
duration<float,milli> duration= endtime-startTime;
double finalTime= duration.count();
cout<<finalTime<<" ms";
    return 0;
}