#include <iostream>
using namespace std;

struct Personaje {
    char tipo;  // 'P' PacMan, 'F' Fantasma
    int x, y; // aunque solo necesitamos la x
};
        

class PacMan {
private:
    char tablero[10][10];  // Supongamos un tablero fijo de 10x10
    int filas, columnas;
    
public:
PacMan(char tableroInicial[10][10], int filas, int columnas) { // SOLO DEFINIMOS EL CONSTRUCTOR
    // PARA EL CASO DE PRUEBA. EL ENUNCIADO ACLARA QUE EL TABLERO SUPONGA QUE YA ESTA INICIALIZADO
    for(int i = 0; i < filas; i++)
        for(int j = 0; j < columnas; j++)
        tablero[i][j] = tableroInicial[i][j];
}
    
void summary() {
Personaje personajes[5];  // Máximo 1 PacMan + 4 Fantasmas
int numPersonajes = 0;
int pastillas = 0;
int vacias = 0;

// Recorrer el tablero
for(int i = 0; i < filas; i++) {
    for(int j = 0; j < columnas; j++) {
        
        if(tablero[i][j] == 'P') {  // Pac-Man
            personajes[numPersonajes].tipo = 'P';
            personajes[numPersonajes].x = j;
            personajes[numPersonajes].y = i;
            numPersonajes++;
        }
        else if(tablero[i][j] == 'F') {  // Fantasma
            personajes[numPersonajes].tipo = 'F';
            personajes[numPersonajes].x = j;
            personajes[numPersonajes].y = i;
            numPersonajes++;
        }
        else if(tablero[i][j] == '*') {  // Pastilla
            pastillas++;
        }
        else if(tablero[i][j] == ' ') {  // Vacío
            vacias++;
        }
    }
}

// Ordenar personajes por X (método burbuja simple)
for(int i = 0; i < numPersonajes - 1; i++) {
    for(int j = 0; j < numPersonajes - i - 1; j++) {
        if(personajes[j].x > personajes[j+1].x) {
            // Intercambiar
            Personaje temp = personajes[j];
            personajes[j] = personajes[j+1];
            personajes[j+1] = temp;
        }
    }
}

// Mostrar resultados
cout << "Personajes ordenados por X:" << endl;
for(int i = 0; i < numPersonajes; i++) {
    cout << (personajes[i].tipo == 'P' ? "Pac-Man" : "Fantasma");
    cout << " en (" << personajes[i].x << "," << personajes[i].y << ")" << endl;
}

 cout << "Pastillas: " << pastillas << endl;
 cout << "Casillas vacías: " << vacias << endl;
 }
};

int main() {
    // Ejemplo de tablero (10x10)
    // SUPONEMOS UN 10X10 PARA DAR UN CASO DE PRUEBA
    char tableroEjemplo[10][10] = {
        {' ', ' ', 'F', ' ', '*', ' ', ' ', ' ', ' ', ' '},
        {' ', '*', ' ', ' ', ' ', 'F', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', 'P', ' ', ' ', ' ', '*', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', 'F', ' ', ' ', ' '},
        {' ', ' ', '*', ' ', ' ', ' ', ' ', ' ', 'F', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
        {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '}
    };
    
    PacMan juego(tableroEjemplo, 10, 10);
    juego.summary();
    
    return 0;
}