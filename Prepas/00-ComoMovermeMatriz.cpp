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

void RecorrerDesdePunto(int **Matriz, int MaxFila, int MaxCol, int Fila, int Columna) {
    cout << "Recorriendo desde el punto: [" << Fila << "][" << Columna << "] = " << Matriz[Fila][Columna] << endl;

    // Usamos arreglos de dirección para simplificar los 8 movimientos
    // [Arriba, Abajo, Izq, Der, SupIzq, SupDer, InfIzq, InfDer]
    int direccionFila[] = {-1, 1,  0, 0, -1, -1,  1, 1};
    int direccionCol[] = { 0, 0, -1, 1, -1,  1, -1, 1};
    string nombres[] = {"Arriba", "Abajo", "Izquierda", "Derecha", 
                        "Sup. Izquierda", "Sup. Derecha", "Inf. Izquierda", "Inf. Derecha"};

    for (int i = 0; i < 8; i++) {
        cout << "\nDireccion " << nombres[i] << ": ";
        
        int SiguienteFila = Fila + direccionFila[i]; // Siguiente fila
        int SiguienteCol = Columna + direccionCol[i]; // Siguiente columna

        // Mientras estemos dentro de los bordes de la matriz
        while (SiguienteFila >= 0 && SiguienteFila < MaxFila && SiguienteCol >= 0 && SiguienteCol < MaxCol) {
            cout << "[" << Matriz[SiguienteFila][SiguienteCol] << "] ";
            
            // Avanzamos un paso más en la misma dirección
            SiguienteFila += direccionFila[i];
            SiguienteCol += direccionCol[i];
        }
    }
    cout << endl;
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
        Tamaño= 3;
    }while(Tamaño % 2 ==0);

    int **Matriz = new int*[Tamaño];
    for(int i=0; i < Tamaño; i++){
        Matriz[i] = new int[Tamaño];
    } 
    int PosicionCentral = Tamaño/2;
    /*
    Imaginemos que tenemos la matriz 3*3
    (dentro de los corchetes sus respectivos indices)
    [0,0][0,1][0,2]
    [1,0][1,1][1,2]
    [2,0][2,1][2,2]
    y quiero moverme apartir del centro a todas las direcciones
    [         ] [Arriba] [       ]
    [Izquierda] [Centro] [Derecha]
    [         ] [Abajo ] [       ]
    Es simple, tomamos la posicion Centrar (este caso Fila 1 col 1)
    Y calculamos los indices para un movimiento
    Arriba = Fila - 1
    Abajo = Fila + 1
    Izquierda = Col - 1
    Derecha = Col + 1

    Ahora, si quiero moverme en las diagonales tendria que hacer 2 Movimientos
    [Principal Superior ] [      ] [Secundaria Superior]
    [                   ] [Centro] [                   ]
    [Secundaria Inferior] [      ] [Principal Inferior]
    
    Diagonal Principal 
        Superior : Arriba e Izquierda 
        Superior = [Fila-1][Col-1]
        Inferior : Abajo y derecha
        Inferior = [Fila+1][Col+1]

    Diagonal Secundaria
        Superior : Arriba e Derecha 
        Superior = [Fila-1][Col+1]
        Inferior : Abajo y izquierda
        Inferior = [Fila+1][Col-1]
    

    Con Arriba Abajo recorremos la matri de forma Vertical
    Con Izquierda derecha recorremos la matriz de forma horizontal
    
    Con la diagonal inferior y superior las diagonales de una matriz
    [Fila, Col]
    [-1,-1]  [-1, 0]  [-1,+1] 
    [ 0,-1]  [ 0, 0]  [ 0,+1] 
    [+1,-1]  [+1, 0]  [+1,+1] 

    */
    
    LlenarMatriz(Matriz, Tamaño, Tamaño);
    MostrarMatriz(Matriz, Tamaño, Tamaño);
    RecorrerDesdePunto(Matriz, Tamaño, Tamaño, PosicionCentral, PosicionCentral);



    for(int i=0; i< Tamaño; i++){
        delete[] Matriz[i];
    }
    delete[] Matriz;

    return 0;
}