/*Dados dos Arreglos ordenados de enteros A y B, haga una función que
permita obtener un tercer Arreglo C que contenga todos los elementos de
A y B ordenados. Por ejemplo, si A = {1, 4, 9} y B = {2, 5, 10, 12}, el
resultado deberá ser C = {1, 2, 4, 5, 9, 10, 12}.*/

#include<iostream>
#include <cstdlib> 
#include <ctime>
using namespace std;    


void LlenarArreglo(int *Arreglo, int Tamaño){
    for(int i = 0; i < Tamaño; i++){
        Arreglo[i] = rand() % 100 + 1;
    }
}

void MostrarArreglo(int *Arreglo, int Tamaño, char letra){
    cout<<"Elementos del Arreglo"<<letra<<":";
    for(int i = 0; i < Tamaño; i++){
        cout<<" "<<Arreglo[i]<<" ";
    }
    cout<<endl;
}
//Para ejemplificar, Tamaño = 4
//Arreglo = [1][3][4][2]
//Indices =  0  1  2  3
void bubbleSort(int *Arreglo, int Tamaño) { 
    for (int i = 0; i < Tamaño - 1; i++) { //Indices i=0 hasta i = Tamaño - 2; i = 4 - 2, i = 2, 0-2
        // El flag 'Cambiado' optimiza el código si el Arreglo ya está ordenado
        bool Cambiado = false;
        
        for (int j = 0; j < Tamaño - i - 1; j++) {
            if (Arreglo[j] > Arreglo[j + 1]) {
                // Intercambio de valores
                int temp = Arreglo[j];
                Arreglo[j] = Arreglo[j + 1];
                Arreglo[j + 1] = temp;
                Cambiado = true;
            }
        }
        
        // Si no hubo intercambios en la pasada, el Arregloay ya está listo
        if (!Cambiado) break;
    }
}

int main(){
    srand(time(0));
    //Con fines practicos de no poner el tamaño manual, no parar bolas 
    int TamañoA = rand() % 10 + 1;
    int TamañoB = rand() % 10 + 1;



    int *ArregloA = new int[TamañoA];
    int *ArregloB = new int[TamañoB];

    //LLena el Arreglo con numeros al azar, para no hacerlo manual
    LlenarArreglo(ArregloA, TamañoA);
    LlenarArreglo(ArregloB, TamañoB);
    
    //Se ordenan los Arreglos antes de mostrarlos
    bubbleSort(ArregloA, TamañoA);
    bubbleSort(ArregloB, TamañoB);
    
    MostrarArreglo(ArregloA, TamañoA, 'A');
    MostrarArreglo(ArregloB, TamañoB, 'B');


    int TamañoC = TamañoA + TamañoB; //El nuevo Arreglo 'C' es el tamaño del Arreglo A y B
    int *ArregloC = new int[TamañoC]; //Reservamos memoria
    //Tenemos por ejemplo TamañoA = 3 y TamañoB = 3
    //ArregloA = [5][6][7]
    //ArregloA = [8][9][10]
    //TamañoC = 6
    //ArregloC = [][][][][][] 6 Posiciones!

    //Aquí empieza la magia
    for(int i = 0; i < TamañoA; i++){//Indices, desde i=0 hasta i = TamañoA-1 (TamañoA=3 entonces i iria de 0 hasta 2)
        //Primero llenamos el Arreglo C con lo que hay en el Arreglo A
        ArregloC[i] = ArregloA[i]; //Es simple, recuerden que el tamaño del Arreglo C es TamañoA+TamañoB por ende no habra acceso fuera de indices
    }
    //ArregloC = [5][6][7][][][], tiene los elementos de A
    

    //Aqui se complica un poco
    for(int i = 0; i < TamañoB; i++){//Indices, desde i=0 hasta i = tamañoB-1
        ArregloC[i + TamañoA] = ArregloB[i]; //¿Por qué accedemos al indice 'i + TamañoA'
        //Porque tenemos que seguir llenando el ArregloC apartir de la posicion que lo dejamos con Arregloglo A

        //Justamente...        AQUI
        //ArregloC = [5][6][7]>>[]<<[][]
        //Indices     0  1  2   3   4  5
        //Si TamañoA = 3, en la primera iteracion sería i=0, 0+3 = 3
        //La segunda i=1, 1+3 = 4
        //Y asi sucesivamente hasta que i = TamañoB-1
    }
    //ArregloC = [5][6][7][8][9][10] Asi quedaría con B


    //En Todo caso, mandamos C a ordenar 
    bubbleSort(ArregloC, TamañoC);
    MostrarArreglo(ArregloC, TamañoC, 'C');

    delete[] ArregloA;
    delete[] ArregloB;
    delete[] ArregloC;
    return 0;
}