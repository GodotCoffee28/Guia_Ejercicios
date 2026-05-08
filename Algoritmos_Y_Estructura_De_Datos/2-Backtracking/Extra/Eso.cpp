#include <iostream> // Para std::cout, std::endl
#include <vector>   // Para std::vector

// Definición de la clase Movimiento
// Representa una posición (fila, columna) dentro del laberinto.
class Movimiento {
public:
    int fila;    // Índice de la fila
    int columna; // Índice de la columna

    // Constructor por defecto: inicializa a (0, 0)
    Movimiento() : fila(0), columna(0) {}

    // Constructor con parámetros: inicializa con los valores proporcionados
    Movimiento(int _fila, int _columna) : fila(_fila), columna(_columna) {}

    // Opcional: Para facilitar la impresión de un objeto Movimiento
    //friend std::ostream& operator<<(std::ostream& os, const Movimiento& m) {
    //    os << "(" << m.fila << ", " << m.columna << ")";
    //    return os;
    //}
};

// Función para inicializar los movimientos posibles (arriba, abajo, izquierda, derecha)
// Esto es útil para iterar a través de las direcciones adyacentes desde una posición.
void inicializarMovimientosDireccionales(Movimiento movimientos[]) {
    // Definimos los 4 movimientos básicos:
    // Arriba
    movimientos[0] = Movimiento(-1, 0);
    // Abajo
    movimientos[1] = Movimiento(1, 0);
    // Izquierda
    movimientos[2] = Movimiento(0, -1);
    // Derecha
    movimientos[3] = Movimiento(0, 1);

    // Si tuvieras 8 direcciones (incluyendo diagonales), añadirías:
    // movimientos[4] = Movimiento(-1, -1); // Arriba-izquierda
    // movimientos[5] = Movimiento(-1, 1);  // Arriba-derecha
    // movimientos[6] = Movimiento(1, -1);  // Abajo-izquierda
    // movimientos[7] = Movimiento(1, 1);   // Abajo-derecha
}

// Ejemplo de cómo usarlo en el main
int main() {
    // Creamos un arreglo de Movimiento para almacenar las direcciones
    // Asumimos 4 direcciones (arriba, abajo, izquierda, derecha)
    Movimiento direccionesPosibles[4];

    // Inicializamos el arreglo con las direcciones
    inicializarMovimientosDireccionales(direccionesPosibles);

    std::cout << "Movimientos direccionales posibles:" << std::endl;
    for (int i = 0; i < 4; ++i) {
        std::cout << "Direccion " << i+1 << ": (fila: "
                << direccionesPosibles[i].fila << ", columna: "
                << direccionesPosibles[i].columna << ")" << std::endl;
    }

    // Ejemplo de cómo usar un objeto Movimiento para una posición específica
    Movimiento inicioLaberinto(0, 0);
    Movimiento salidaLaberinto(9, 9); // Para un laberinto 10x10

    std::cout << "\nPosicion de inicio: (fila: " << inicioLaberinto.fila
            << ", columna: " << inicioLaberinto.columna << ")" << std::endl;
    std::cout << "Posicion de salida: (fila: " << salidaLaberinto.fila
            << ", columna: " << salidaLaberinto.columna << ")" << std::endl;

    return 0;
}

/*funcion resolverLaberinto(laberinto, fila_actual, columna_actual, fila_destino, columna_destino, N, camino_solucion):
    // 1. Caso base: Si hemos llegado al destino
    si fila_actual == fila_destino Y columna_actual == columna_destino:
        agregar (fila_actual, columna_actual) a camino_solucion
        retornar verdadero (encontramos un camino)

    // 2. Marcar la celda actual como visitada (para evitar ciclos)
    marcar laberinto[fila_actual][columna_actual] como visitada

    // 3. Probar los movimientos posibles (Arriba, Abajo, Izquierda, Derecha)
    para cada Movimiento direccion en direccionesPosibles:
        nueva_fila = fila_actual + direccion.fila
        nueva_columna = columna_actual + direccion.columna

        // 4. Validar el movimiento
        si (nueva_fila es válida Y nueva_columna es válida)          // Dentro de los límites del laberinto
        Y (laberinto[nueva_fila][nueva_columna] es un camino (0)) // No es una pared
        Y (laberinto[nueva_fila][nueva_columna] NO ha sido visitada): // No hemos estado aquí antes

            // 5. Moverse a la nueva celda y recursivamente intentar resolver desde allí
            agregar (nueva_fila, nueva_columna) a camino_solucion
            si resolverLaberinto(laberinto, nueva_fila, nueva_columna, fila_destino, columna_destino, N, camino_solucion):
                retornar verdadero (se encontró un camino a través de esta ruta)
            sino:
                // Si el camino no lleva a la salida, retroceder (backtrack)
                remover la última posición de camino_solucion
                // (Opcional) desmarcar laberinto[nueva_fila][nueva_columna] como visitada
                // Esto depende de cómo manejes el estado 'visitado' (si es global o por path)

    // 6. Si ningún movimiento desde aquí lleva a la salida
    retornar falso
    */