#include <iostream>
#include <fstream>
using namespace std;

int modelos[300];
int colores[100];

struct Automoviles
{
    int modelo;
    int color;
};

void Aparcados(Automoviles** estacionamiento[][], int N, int M){ // SOLO MODELADO DE MATRIZ DINAMICA
    // Se buscan los datos
    // Se llenas los arreglos con la frecuencia de aparicion de vehiculos por: modelo y color
    for(int i = 0; i < N; i++){
        for(int j = 0; j < M; j++){
            modelos[estacionamiento[i][j].modelo - 1]++;
            colores[estacionamiento[i][j].color - 1]++;
        }
    }
    // Se busca en el arreglo donde guardamos la frecuencia de aparicion
    // por color y buscamos el mas frecuente (el mayor)
    int colorFrecuente = -1;
    for(int i = 0; i < 100; i++){
        if(colores[i] > colorFrecuente)
        colorFrecuente = colores[i];
    }
// Insertamos los datos recolectados en el archivo propuesto del enunciado
ofstream result("resultado.txt");
if(!result.is_open()){
    cout << "No se abrio 'resultado.txt'";
    return;
}
// apartado (a)
for(int i = 0; i < 300; i++){
    result << "Modelo " << i << ": " << modelos[i] << " ";
}
// apartado (b)
result << endl << colorFrecuente;

result.close();

}

