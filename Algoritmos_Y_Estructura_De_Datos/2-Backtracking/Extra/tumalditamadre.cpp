#include<iostream>
using namespace std;
// Define los tipos de entidades como constantes con nombres significativos
enum TipoEntidad {
    NULO = -1,  // Para representar un espacio vacío en la barca o en una orilla
    PASTOR = 0, // El pastor
    LOBO = 1,   // El lobo
    OVEJA = 2,  // La oveja
    COL = 3     // La col
};

class SerVivo {
public:
    string Nombre;
    TipoEntidad Tipo; // Ahora 'Tipo' es de tipo TipoEntidad
    // Agregamos un constructor por defecto para inicializar con NULO
    SerVivo() : Nombre(""), Tipo(NULO) {};
    SerVivo(string _Nombre, TipoEntidad _Tipo) : Nombre(_Nombre), Tipo(_Tipo) {};

    // La función PuedeEstar tal como la tienes no es la forma ideal de chequear las reglas
    // La lógica de "comer" la moveremos a una función separada que validará el estado
    // Puedes quitar 'PuedeEstar' de aquí, o dejarla si tienes otro propósito para ella.
    // void PuedeEstar(SerVivo Primero, SerVivo Segundo){ ... }
};
bool esEstadoValido(const SerVivo orilla[]) {
    // Necesitamos saber quién está en esta orilla
    bool hayPastor = false;
    bool hayLobo = false;
    bool hayOveja = false;
    bool hayCol = false;

    for (int k = 0; k < 4; ++k) { // Iteramos sobre los 4 posibles espacios en la orilla
        if (orilla[k].Tipo == PASTOR) hayPastor = true;
        else if (orilla[k].Tipo == LOBO) hayLobo = true;
        else if (orilla[k].Tipo == OVEJA) hayOveja = true;
        else if (orilla[k].Tipo == COL) hayCol = true;
    }

    // Regla 1: Si el pastor NO está, y el lobo Y la oveja están, es inválido
    if (!hayPastor && hayLobo && hayOveja) {
        return false;
    }
    // Regla 2: Si el pastor NO está, y la oveja Y la col están, es inválido
    if (!hayPastor && hayOveja && hayCol) {
        return false;
    }

    return true; // El estado en esta orilla es seguro
}

// Añadimos un parámetro para el lado actual del pastor (true = izquierda, false = derecha)
// y un contador de movimientos para evitar ciclos infinitos y límite.
bool LaCanoa(SerVivo LadoIzquierdo[], SerVivo LadoDerecho[], int movimientos = 0, bool pastorEnIzquierda = true) {
    // *** 0. Condición de Éxito (Caso Base) ***
    // Si todos (lobo, oveja, col, pastor) están en el lado derecho, ¡éxito!
    bool pastorEnDerecha = false, loboEnDerecha = false, ovejaEnDerecha = false, colEnDerecha = false;
    for (int k = 0; k < 4; ++k) {
        if (LadoDerecho[k].Tipo == PASTOR) pastorEnDerecha = true;
        else if (LadoDerecho[k].Tipo == LOBO) loboEnDerecha = true;
        else if (LadoDerecho[k].Tipo == OVEJA) ovejaEnDerecha = true;
        else if (LadoDerecho[k].Tipo == COL) colEnDerecha = true;
    }

    if (pastorEnDerecha && loboEnDerecha && ovejaEnDerecha && colEnDerecha) {
        cout << "¡Solución encontrada!" << endl;
        // Aquí podrías imprimir los movimientos que llevaron a esta solución
        return true; // Terminamos, hemos encontrado una solución
    }

    // *** 1. Condición de Parada para evitar bucles infinitos ***
    // Un número máximo de movimientos para evitar bucles.
    if (movimientos > 20) { // Un número razonable de movimientos para este acertijo
        return false;
    }

    // *** 2. Identificar el Pastor y los posibles acompañantes en la orilla actual ***
    // Necesitamos encontrar el Pastor y los otros elementos en la orilla donde está el Pastor.
    SerVivo* orillaActual;
    SerVivo* otraOrilla;

    if (pastorEnIzquierda) {
        orillaActual = LadoIzquierdo;
        otraOrilla = LadoDerecho;
    } else {
        orillaActual = LadoDerecho;
        otraOrilla = LadoIzquierdo;
    }

    // Encontrar al pastor en la orilla actual
    int pastorIndex = -1;
    for (int k = 0; k < 4; ++k) {
        if (orillaActual[k].Tipo == PASTOR) {
            pastorIndex = k;
            break;
        }
    }

    // Si por alguna razón el pastor no está en la orilla actual (lo cual no debería pasar si el estado es consistente)
    if (pastorIndex == -1) return false;

    // *** 3. Explorar los posibles movimientos desde la orilla actual ***
    // El pastor puede ir solo, o con lobo, oveja o col.
    // Necesitamos simular el movimiento de cada uno de ellos.

    // Un array temporal para la barca para simular el movimiento
    SerVivo barcaTemporal[2];

    // Iterar a través de las 4 posibilidades de acompañante (0 = solo, 1=lobo, 2=oveja, 3=col)
    // Cuidado: el orden de los SerVivo en el arreglo de la orilla no es fijo si se mueven.
    // Es mejor iterar sobre los tipos de entidades que el pastor puede llevar.
    TipoEntidad posiblesAcompanantes[] = {NULO, LOBO, OVEJA, COL}; // NULO significa que el pastor va solo

    for (int i = 0; i < sizeof(posiblesAcompanantes)/sizeof(posiblesAcompanantes[0]); ++i) {
        TipoEntidad acompananteTipo = posiblesAcompanantes[i];

        // Verificar si el acompañante existe en la orilla actual
        bool acompananteExiste = false;
        int acompananteIndex = -1;
        if (acompananteTipo != NULO) {
            for (int k = 0; k < 4; ++k) {
                if (orillaActual[k].Tipo == acompananteTipo) {
                    acompananteExiste = true;
                    acompananteIndex = k;
                    break;
                }
            }
        } else {
            // Si el acompañante es NULO, el pastor va solo. No necesitamos encontrarlo.
            acompananteExiste = true;
        }

        if (acompananteExiste) { // Si el acompañante que queremos llevar existe en la orilla
            // *** A. Simular el movimiento: Mover del orillaActual a la barca ***

            // Copia del estado actual para esta rama de la recursión
            SerVivo nextLadoIzquierdo[4];
            SerVivo nextLadoDerecho[4];
            for(int k=0; k<4; ++k) {
                nextLadoIzquierdo[k] = LadoIzquierdo[k];
                nextLadoDerecho[k] = LadoDerecho[k];
            }

            // Marca el pastor y el acompañante (si lo hay) como NULO en la orilla de origen
            if (pastorEnIzquierda) {
                nextLadoIzquierdo[pastorIndex].Tipo = NULO;
                if (acompananteTipo != NULO) {
                    nextLadoIzquierdo[acompananteIndex].Tipo = NULO;
                }
            } else { // Pastor en la derecha
                nextLadoDerecho[pastorIndex].Tipo = NULO;
                if (acompananteTipo != NULO) {
                    nextLadoDerecho[acompananteIndex].Tipo = NULO;
                }
            }

            // *** B. Simular el movimiento: Mover de la barca a la otra orilla ***
            // Encuentra el primer espacio NULO en la otra orilla para el pastor y el acompañante
            int pastorDestinoIndex = -1, acompananteDestinoIndex = -1;
            for (int k = 0; k < 4; ++k) {
                if ((pastorEnIzquierda ? nextLadoDerecho[k].Tipo : nextLadoIzquierdo[k].Tipo) == NULO) {
                    if (pastorDestinoIndex == -1) pastorDestinoIndex = k;
                    else if (acompananteTipo != NULO && acompananteDestinoIndex == -1) acompananteDestinoIndex = k;
                    if (pastorDestinoIndex != -1 && (acompananteTipo == NULO || acompananteDestinoIndex != -1)) break;
                }
            }
            if (pastorDestinoIndex == -1 || (acompananteTipo != NULO && acompananteDestinoIndex == -1)) {
                // Esto no debería ocurrir si hay espacio en la otra orilla, pero es una buena verificación
                continue;
            }

            if (pastorEnIzquierda) { // Pastor y acompañante llegan a la derecha
                nextLadoDerecho[pastorDestinoIndex].Tipo = PASTOR;
                nextLadoDerecho[pastorDestinoIndex].Nombre = "Pastor";
                if (acompananteTipo != NULO) {
                    nextLadoDerecho[acompananteDestinoIndex].Tipo = acompananteTipo;
                    // Asigna el nombre adecuado al acompañante
                    if (acompananteTipo == LOBO) nextLadoDerecho[acompananteDestinoIndex].Nombre = "Lobo";
                    else if (acompananteTipo == OVEJA) nextLadoDerecho[acompananteDestinoIndex].Nombre = "Oveja";
                    else if (acompananteTipo == COL) nextLadoDerecho[acompananteDestinoIndex].Nombre = "Col";
                }
            } else { // Pastor y acompañante llegan a la izquierda
                nextLadoIzquierdo[pastorDestinoIndex].Tipo = PASTOR;
                nextLadoIzquierdo[pastorDestinoIndex].Nombre = "Pastor";
                if (acompananteTipo != NULO) {
                    nextLadoIzquierdo[acompananteDestinoIndex].Tipo = acompananteTipo;
                    if (acompananteTipo == LOBO) nextLadoIzquierdo[acompananteDestinoIndex].Nombre = "Lobo";
                    else if (acompananteTipo == OVEJA) nextLadoIzquierdo[acompananteDestinoIndex].Nombre = "Oveja";
                    else if (acompananteTipo == COL) nextLadoIzquierdo[acompananteDestinoIndex].Nombre = "Col";
                }
            }

            // Imprimir el movimiento actual para depuración
            cout << "Movimiento " << movimientos + 1 << ": Pastor ";
            if (acompananteTipo != NULO) {
                cout << "y " << SerVivo("", acompananteTipo).Nombre; // Nombre es temporal para imprimir
            }
            cout << (pastorEnIzquierda ? "de Izquierda a Derecha." : "de Derecha a Izquierda.") << endl;
            // (Necesitarás una forma de obtener el nombre a partir del TipoEntidad para imprimir)

            // *** C. Verificar si el nuevo estado es válido ***
            if (esEstadoValido(nextLadoIzquierdo) && esEstadoValido(nextLadoDerecho)) {
                // *** D. Llamada Recursiva (Explorar el siguiente paso) ***
                // Si esta llamada recursiva encuentra una solución, entonces este camino es válido.
                if (LaCanoa(nextLadoIzquierdo, nextLadoDerecho, movimientos + 1, !pastorEnIzquierda)) {
                    return true; // ¡Se encontró una solución en una rama posterior!
                }
            }
            // *** E. Backtracking (No necesitas deshacer explícitamente porque trabajamos con copias) ***
            // Si la llamada recursiva anterior retorna 'false' (no encontró solución),
            // simplemente esta iteración del bucle terminará y la siguiente iteración probará otro movimiento.
            // La copia de los arrays asegura que no modificamos el estado de otras ramas.
        }
    }

    return false; // Ninguno de los movimientos posibles desde este estado llevó a una solución
}

int main() {
    // Inicialización con el nuevo enum TipoEntidad
    SerVivo OrillaIzquierda[4];
    OrillaIzquierda[0] = SerVivo("Pastor", PASTOR);
    OrillaIzquierda[1] = SerVivo("Lobo", LOBO);
    OrillaIzquierda[2] = SerVivo("Oveja", OVEJA);
    OrillaIzquierda[3] = SerVivo("Col", COL);

    SerVivo OrillaDerecha[4]; // Se inicializan automáticamente a NULO
    // No necesitamos la barca como un arreglo persistente fuera de la función recursiva,
    // ya que su contenido cambia con cada movimiento y se simula dentro de la función.

    cout << "Intentando resolver el acertijo del Pastor, Oveja, Lobo y Col..." << endl;

    if (!LaCanoa(OrillaIzquierda, OrillaDerecha, 0, true)) {
        cout << "No se encontró una solución para el acertijo." << endl;
    }

    return 0;
}