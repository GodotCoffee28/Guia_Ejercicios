#include <iostream>
#include <fstream>
using namespace std;

class Hortaliza {
private:
    int tipo;       // código del tipo (1 a 2000)
    float volumen;  // en cm³
public:
    // Constructores
    Hortaliza() : tipo(0), volumen(0) {}
    Hortaliza(int t, float v) : tipo(t), volumen(v) {}

    // Métodos de acceso
    int getTipo(){ return tipo; }
    float getVolumen(){ return volumen; }

};

// Función Control solicitada
void Control(Hortaliza terreno[5][5], int N, int M) { //SE SUPONE DE ESE TAMANIO PARA
                // EL CASO DE PRUEBA
    // Contadores para cada tipo (máx 2000)
    int contadorTipos[2000];  // MISMA LOGICA QUE EN EL DE AUTOMOVILES
    int comercializables = 0;

    // Recorrer la matriz
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {

            contadorTipos[terreno[i][j].getTipo() - 1]++;
            if (terreno[i][j].getVolumen() >= 10.0) {
                comercializables++;
            }
        }
    }

    // Escribir archivo de salida
    ofstream archivo("salida.txt");
    if (!archivo.is_open()) {
        cout << "Error al crear el archivo salida.txt" << endl;
        return;
    }

    archivo << "Número de hortalizas de cada tipo:" << endl;
    for (int i = 1; i <= 2000; i++) {

      archivo << "Tipo " << i + 1 << ": " << contadorTipos[i] << endl;

    }
    archivo << "Hortalizas comercializables: " << comercializables << endl;

    archivo.close();
}

// CASO DE PRUEBA
int main() {
    // Crear una matriz de ejemplo de 5x10
    Hortaliza terreno[5][5] = {
        { Hortaliza(1, 15.5), Hortaliza(2, 8.0),  Hortaliza(1, 20.0), Hortaliza(3, 5.0),  Hortaliza(2, 12.0) },
        { Hortaliza(3, 25.0), Hortaliza(1, 9.5),  Hortaliza(2, 30.0), Hortaliza(4, 7.0),  Hortaliza(1, 18.0) },
        { Hortaliza(2, 11.0), Hortaliza(4, 22.0), Hortaliza(3, 4.0),  Hortaliza(1, 16.0), Hortaliza(2, 14.0) },
        { Hortaliza(5, 13.0), Hortaliza(3, 19.0), Hortaliza(1, 10.0), Hortaliza(2, 6.0),  Hortaliza(4, 17.0) },
        { Hortaliza(1, 21.0), Hortaliza(2, 24.0), Hortaliza(5, 8.5),  Hortaliza(3, 23.0), Hortaliza(4, 9.0) }
    };

    // NOTA!!!: NI LOS CONSTRUCTORES NI EL MAIN NI LOS GETTERS SON NECESARIOS AL MOMENTO DE LA EVALUACION,
    // SOLO LOS HAGO PARA EL CASO DE PRUEBA
    Control(terreno, 5, 5);

    cout << "Archivo 'salida.txt' generado correctamente." << endl;
    return 0;
}