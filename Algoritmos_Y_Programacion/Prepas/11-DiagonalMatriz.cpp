/*Haga una función que tome como entrada una matriz cuadrada y retorne
la suma de los elementos de la diagonal secundaria.*/


#include<iostream>
#include <cstdlib> 
#include <ctime>
using namespace std;   

int CalcularDiagonal(int **Matriz, int Tamaño){ 
    int Suma = 0;
    int Fila = Tamaño - 1;
    int Columna = 0;
    for(int i = 0; i < Tamaño; i++){
        Suma+= Matriz[Fila][Columna];
        Fila--;
        Columna++;
    }
    return Suma;
}



/*int CalcularDiagonal(int **Matriz, int Tamaño, bool hola){ 
    int Suma = 0;

    for(int i = 0; i < Tamaño; i++){
        Suma+= Matriz[Tamaño - i - 1][i];
    }
    return Suma;
}*/
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
    int Tamaño = rand() % 10 + 2;

    int **MatrizCuadrada = new int*[Tamaño];

    for(int i = 0; i < Tamaño; i++){
        MatrizCuadrada[i] = new int[Tamaño];
    }
    LlenarMatriz(MatrizCuadrada, Tamaño, Tamaño);
    cout<<"El tamaño de la matriz es: "<<Tamaño<<endl;
    MostrarMatriz(MatrizCuadrada, Tamaño, Tamaño);

    int SumaDiagonal = CalcularDiagonal(MatrizCuadrada, Tamaño);
    
    cout<<"La suma de los elementos de la diagonal de la matriz es = "<<SumaDiagonal;

    for(int i = 0; i < Tamaño; i++) {
        delete[] MatrizCuadrada[i]; // Liberar columnas
    }
    delete[] MatrizCuadrada; // Liberar filas

    return 0;
}