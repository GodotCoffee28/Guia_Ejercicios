#include<iostream>
#include <cstdlib> 
#include <ctime>
using namespace std;   


void MostrarMatriz(int **Matriz, int Fila, int Col, char letra = ' '){
    cout<<"Elementos de la Matriz "<<letra<<": "<<endl;
    for(int i=0; i < Fila; i++){
        for(int j=0; j<Col; j++){
            int num = Matriz[i][j];
            cout << "[" << num << "]";

            // Agregamos espacios fuera según el tamaño del número
            // Si es un número de un dígito positivo (ej: [5])
            if (num >= 0 && num < 10) {
                cout << "   "; // Tres espacios
            } 
            // Si tiene dos dígitos o es negativo de uno (ej: [14] o [-5])
            else if ((num >= 10 && num < 100) || (num < 0 && num > -10)) {
                cout << "  ";  // Dos espacios
            }
            // Si es negativo de dos dígitos (ej: [-14])
            else {
                cout << " ";   // Un espacio
            }
        }
        cout<<endl;
    }
    cout<<endl;
}
void LlenarMatriz( int **Matriz, int Fila, int Col){
    for(int i=0; i < Fila; i++){
        for(int j=0; j<Col; j++){
            Matriz[i][j] = rand() % 25;
        }
    }
}


int main(){

    srand(time(0));
    int Tamaño;


    do{
        Tamaño = rand() % 10 + 2;
    }while(Tamaño% 2 == 0);
    

    int **Matriz = new int*[Tamaño];
    for(int i=0; i < Tamaño; i++){
        Matriz[i] = new int[Tamaño];
    } 

    LlenarMatriz(Matriz, Tamaño, Tamaño);
    MostrarMatriz(Matriz, Tamaño, Tamaño);

    int Arriba = 0, Abajo = Tamaño - 1,
        Izquierda = 0, Derecha = Tamaño - 1;


    while(Arriba <= Abajo && Izquierda <= Derecha ){
        // 1. Derecha 
        cout << "Moviendo Derecha: ";
        for(int j = Izquierda; j <= Derecha; ++j){
            cout << "[" << Matriz[Arriba][j] << "]";
        }
        Arriba++; 
        cout << endl;

        // 2. Abajo 
        cout << "Moviendo Abajo: ";
        for(int i = Arriba; i <= Abajo; ++i){
            cout << "[" << Matriz[i][Derecha] << "]";
        }
        Derecha--;
        cout << endl;

        // 3. Izquierda 
        if(Arriba <= Abajo){
            cout << "Moviendo Izquierda: ";
            // Empezamos en Derecha y bajamos hasta Izquierda
            for(int j = Derecha; j >= Izquierda; --j){ 
                cout << "[" << Matriz[Abajo][j] << "]"; // Usamos la fila de Abajo
            }
            Abajo--; // El borde inferior sube
            cout << endl;
        }

        // 4. Arriba 
        if(Izquierda <= Derecha){ 
            cout << "Moviendo Arriba: ";
            for(int i = Abajo; i >= Arriba; --i){
                cout << "[" << Matriz[i][Izquierda] << "]";
            }
            Izquierda++; // El borde izquierdo se mueve a la derecha
            cout << endl;
        }
    }

    for(int i=0; i< Tamaño; i++){
        delete[] Matriz[i];
    }
    delete[] Matriz;
    return 0;
}