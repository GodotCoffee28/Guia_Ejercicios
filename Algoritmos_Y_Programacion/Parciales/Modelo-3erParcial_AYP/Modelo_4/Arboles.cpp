#include <iostream>
#include <fstream>
using namespace std;

class Arbol {
private:
    int tipo;       // código del 1 al 150
    float altura;   // en metros
public:
    Arbol() : tipo(0), altura(0) {} // CONSTRUCTORES SOLO HECHOS PARA LOS CASOS DE PRUEBA
    Arbol(int t, float a) : tipo(t), altura(a) {}
    
    int getTipo() const { return tipo; }
    float getAltura() const { return altura; }
};

// Función Stats solicitada
void Stats(Arbol terreno[5][5], int N, int M, float X) { // SUPONEMOS UNA MATRIZ DE 5 x 5 PARA EL EJEMPLO
    // Contadores para cada especie (1..150, es decir indices del 0...149)
    int contadorEspecies[150]; // Suponemos una inicializacion en 0
    int arbolesAltos = 0;             // cantidad con altura > X
    
    // Recorrer la matriz
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            int t = terreno[i][j].getTipo();
            if (t >= 1 && t <= 150) {
                contadorEspecies[t-1]++;
            }
            if (terreno[i][j].getAltura() > X) {
                arbolesAltos++;
            }
        }
    }
    
    // Escribir archivo de salida
    ofstream archivo("bosque.txt");
    if (!archivo) {
        cerr << "Error al crear el archivo bosque.txt" << endl;
        return;
    }
    
    archivo << "Número de árboles de cada especie:" << endl;
    for (int i = 1; i <= 150; i++) {
        if (contadorEspecies[i] > 0) {
            archivo << "Especie " << i << ": " << contadorEspecies[i - 1] << endl;
        }
    }
    archivo << "Árboles con altura mayor a " << X << " m: " << arbolesAltos << endl;
    
    archivo.close();
}

// Ejemplo de uso
int main() {
    // Crear una matriz de ejemplo de 5x5
    Arbol bosque[5][5] = {
        { Arbol(1, 12.5), Arbol(2, 8.0),  Arbol(1, 20.0), Arbol(3, 5.5),  Arbol(2, 15.0) },
        { Arbol(3, 25.0), Arbol(1, 9.2),  Arbol(2, 30.0), Arbol(4, 7.0),  Arbol(1, 18.0) },
        { Arbol(2, 11.0), Arbol(4, 22.0), Arbol(3, 4.0),  Arbol(1, 16.0), Arbol(2, 14.0) },
        { Arbol(5, 13.0), Arbol(3, 19.0), Arbol(1, 10.0), Arbol(2, 6.0),  Arbol(4, 17.0) },
        { Arbol(1, 21.0), Arbol(2, 24.0), Arbol(5, 8.5),  Arbol(3, 23.0), Arbol(4, 9.0) }
    };
    
    // Llamar a Stats con altura límite X = 10.0
    Stats(bosque, 5, 5, 10.0);
    
    cout << "Archivo 'bosque.txt' generado correctamente." << endl;
    return 0;
}