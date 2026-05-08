#include<iostream> //stdlib, fstream, string, iostream, math.h o csmath, string, vector, chrono.
#include<fstream>
#include<string>
#include<vector>
#include<math.h>
#include<chrono>
#include <iostream> // Para std::cout, std::endl
#include <vector>   // Para std::vector
#include <string>   // Para std::string y std::getline
#include <fstream>  // Para std::ifstream (lectura de archivos)


using namespace std;

using namespace chrono;

class Movimiento{
    public:
    int fila;
    int colunma;
    Movimiento(): fila(0), colunma(0) {};
    Movimiento(int _fila, int _colunma): fila(_fila), colunma(_colunma){}
};
void MovimientosPosiblesFxC(Movimiento Movimientos[]){ //en terminos de indices de matrices esta seria la forma correcta de moverse en una
    Movimientos[0]= Movimiento(1, 0); // Esto es ABAJO (+1 en fila)
    Movimientos[1]= Movimiento(-1, 0); // Esto es ARRIBA (-1 en fila)
    Movimientos[2]= Movimiento(0, 1); // Esto es DERECHA (+1 en columna)
    Movimientos[3]= Movimiento(0, -1); // Esto es IZQUIERDA (-1 en columna)
    //El orden de prioridad de movimientos importa, esto puede hacer que te muevas FIlasxColunmas
    //en este caso Los movimientos posibles estan de modo FxC
}
void MovimientosPosiblesCxF(Movimiento Movimientos[]){ //en terminos de indices de matrices esta seria la forma correcta de moverse en una
    Movimientos[0]= Movimiento(0, 1); // Esto es DERECHA (+1 en columna)    
    Movimientos[1]= Movimiento(0, -1); // Esto es IZQUIERDA (-1 en columna)
    Movimientos[2]= Movimiento(1, 0); // Esto es ABAJO (+1 en fila)
    Movimientos[3]= Movimiento(-1, 0); // Esto es ARRIBA (-1 en fila)

    //El orden de prioridad de movimientos importa, esto puede hacer que te muevas FIlasxColunmas
    //en este caso Los movimientos posibles estan de modo CxF
}

int InvocacionesRecursivas=0;

bool MazeSolver(int maze[][50], int N, int Fila_Actual, int Colunma_Actual, int Fila_Salida, int Colunma_Salida, Movimiento MovimientoPosible[], bool visitado[][50]){
    InvocacionesRecursivas++;
    if(InvocacionesRecursivas==199){
        cout<<"eres marico";
    }
    if (Fila_Actual==Fila_Salida && Colunma_Actual==Colunma_Salida){ //si en la fila acutal y la columna actual estan en la salida, significa que se resolvio
        maze[Fila_Actual][Colunma_Actual] = 2;
        return true; //
    }   
    visitado[Fila_Actual][Colunma_Actual] = true;
    maze[Fila_Actual][Colunma_Actual] = 2;

        for(int i=0; i<4; i++){
        int Siguiente_Fila=Fila_Actual+MovimientoPosible[i].fila;
        int Siguiente_Colunma=Colunma_Actual+MovimientoPosible[i].colunma;
            if(Siguiente_Fila>=0 && Siguiente_Fila < N && Siguiente_Colunma>=0 && Siguiente_Colunma <N //Comprobamos que la Este movimiento este dentro del laberinto
            && maze[Siguiente_Fila][Siguiente_Colunma]==0 && !visitado[Siguiente_Fila][Siguiente_Colunma]){ //comprobamos que ese lugar no lo hemos visitado y se pueda recorrer
                if(MazeSolver(maze, N, Siguiente_Fila, Siguiente_Colunma, Fila_Salida, Colunma_Salida, MovimientoPosible, visitado)){
                    return true;
                    }
                }
            }
    visitado[Fila_Actual][Colunma_Actual] = false;
    maze[Fila_Actual][Colunma_Actual] = 0;

    return false;
}

bool MazeSolver(int maze[][200], int N, int Fila_Actual, int Colunma_Actual, int Fila_Salida, int Colunma_Salida, Movimiento MovimientoPosible[], bool visitado[][50]){
    InvocacionesRecursivas++;
        if(InvocacionesRecursivas>=199){
        cout<<"eres marico";
    }
    if (Fila_Actual==Fila_Salida && Colunma_Actual==Colunma_Salida){ //si en la fila acutal y la columna actual estan en la salida, significa que se resolvio
        maze[Fila_Actual][Colunma_Actual] = 2;
        return true; //
    }   
    visitado[Fila_Actual][Colunma_Actual] = true;
    maze[Fila_Actual][Colunma_Actual] = 2;

        for(int i=0; i<4; i++){
            if(i==1){
                MovimientoPosible[i].fila =1;
            }
        int Siguiente_Fila=Fila_Actual+MovimientoPosible[i].fila;
        
        int Siguiente_Colunma=Colunma_Actual+MovimientoPosible[i].colunma;
            if(Siguiente_Fila>=0 && Siguiente_Fila < N && Siguiente_Colunma>=0 && Siguiente_Colunma <N //Comprobamos que la Este movimiento este dentro del laberinto
            && maze[Siguiente_Fila][Siguiente_Colunma]==0 && !visitado[Siguiente_Fila][Siguiente_Colunma]){ //comprobamos que ese lugar no lo hemos visitado y se pueda recorrer
                if(MazeSolver(maze, N, Siguiente_Fila, Siguiente_Colunma, Fila_Salida, Colunma_Salida, MovimientoPosible, visitado)){
                    return true;
                    }
                }
            }
    visitado[Fila_Actual][Colunma_Actual] = false;
    maze[Fila_Actual][Colunma_Actual] = 0;

    return false;
}

int main() {
    auto startTime= high_resolution_clock::now();
    Movimiento DireccionesPosibles[4]; 
    const int FILAS = 200;
    const int COLUMNAS = 200;


    // Puedes acceder a cualquier celda así:
    // std::cout << "Valor en [0][0]: " << laberinto_matriz[0][0] << std::endl;
    // std::cout << "Valor en [199][199]: " << laberinto_matriz[199][199] << std::endl;


    int n=200;
    int m=1;
    int k1=1;
    int k2=0;
    float tiempoAcumulado=0;
    int InvocacionesAcumuladas=0;
    int CaminoAcumulado=0;
        bool visitado[50][50];
    for(int i=0; i< 50; i++){
        for(int j=0; j<50; j++){
            visitado[i][j] = false;
        }
    }
    //cout << "Ingrese la dimension del laberinto (10, 20 o 50): ";
    //cin >> n;
    //cout<<"¿Que tipo de movimiento quiere? Filas por Colunma: 1\n Colunmas por Filas: 2"<<endl;
    //cin >>m;
    //cout<< "¿Cuantas veces quiere ejecutar este Backtraking?\n Ingrese las k veces:"
    //cin >> k1;
        int maze[200][200]={0};
    const std::string NOMBRE_ARCHIVO = "Laberinto.txt"; // Asegúrate de que el archivo esté en el mismo directorio que tu ejecutable

    // Declaramos la matriz para el laberinto

    // Abrir el archivo
    std::ifstream archivo_laberinto(NOMBRE_ARCHIVO);

    // Verificar si el archivo se abrió correctamente
    if (!archivo_laberinto.is_open()) {
        std::cerr << "Error: No se pudo abrir el archivo '" << NOMBRE_ARCHIVO << "'" << std::endl;
        return 1; // Salir con un código de error
    }

    // El archivo Laberinto.txt que subiste comienza con "200"
    // Esto indica el tamaño. Necesitamos leerlo antes de procesar el laberinto.
    std::string primera_linea_size;
    std::getline(archivo_laberinto, primera_linea_size); // Leer la línea que contiene "200"
    // Opcional: podrías convertir 'primera_linea_size' a un int y verificar que sea 200.

    // Leer el laberinto línea por línea y llenar la matriz
    std::string linea;
    for (int i = 0; i < FILAS; ++i) {
        if (std::getline(archivo_laberinto, linea)) { // Leer una línea del archivo
            if (linea.length() < COLUMNAS) {
                std::cerr << "Advertencia: La línea " << i + 1 << " es más corta de lo esperado. Contiene " << linea.length() << " caracteres." << std::endl;
                // Puedes decidir cómo manejar esto: rellenar con 0s, con 1s, o lanzar un error.
                // Aquí, solo se llenarán hasta la longitud de la línea.
            }
            for (int j = 0; j < COLUMNAS && j < linea.length(); ++j) {
                if (linea[j] == '1') {
                    maze[i][j] = 1; // Muro
                } else if (linea[j] == '0') {
                    maze[i][j] = 0; // Espacio o Entrada/Salida (si aplica)
                } else {
                    // Manejar caracteres inesperados si los hubiera
                    std::cerr << "Advertencia: Carácter inesperado '" << linea[j] << "' en la fila " << i << ", columna " << j << std::endl;
                    maze[i][j] = 0; // Asumir espacio por defecto o definir otra lógica
                }
            }
        } else {
            std::cerr << "Error: No se pudieron leer todas las filas del laberinto. Se esperaban " << FILAS << " pero se leyeron " << i << "." << std::endl;
            break; // Salir del bucle si no hay más líneas
        }
    }

    // Cerrar el archivo después de usarlo
    archivo_laberinto.close();
    // Cerrar el archivo después de usarlo
    archivo_laberinto.close();

    // Opcional: Imprimir una pequeña parte de la matriz para verificar (200x200 es muy grande para imprimir todo)

    switch (m){
    case 1: MovimientosPosiblesFxC(DireccionesPosibles); break;
    case 2: MovimientosPosiblesCxF(DireccionesPosibles); break;
    default: cout<<"\nNo ingreso ningun tipo de movimiento valido (1/2)\n"; return 0; break;
}
    int ContCasillas=0;
    if(MazeSolver(maze, 200, 0, 0, 199, 199, DireccionesPosibles, visitado)){
        
        
        cout<<"SE HA HALLADO UN CAMINO\n";
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(maze[i][j]==2) {
                    cout<<"P"<<" ";
                    ContCasillas++;
                }
                else if(maze[i][j]==0) cout<<"."<<" ";
                else if(maze[i][j]==1) cout<<"|"<<" ";
            }
        cout<<"\n";
        }
        cout<<"La cantidad de invocaciones recursiva fue de: "<<InvocacionesRecursivas<<endl;
        cout<<"Camino/Casillas recorridas: "<<ContCasillas<<endl;
        auto endtime=high_resolution_clock::now();
        duration<float,milli> duration= endtime-startTime;
        double finalTime= duration.count();
        cout<<finalTime/1000.0<<" segundos";
        tiempoAcumulado+=finalTime/1000;
        InvocacionesAcumuladas+=InvocacionesRecursivas;
        CaminoAcumulado+=ContCasillas;

        
        }else{
            cout<<"NO SE A HALLADO CAMINO\n";
                    for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(maze[i][j]==2) cout<<"P"<<" ";
                else if(maze[i][j]==0) cout<<"."<<" ";
                else if(maze[i][j]==1) cout<<"|"<<" ";
            }
        cout<<"\n";
        }
        cout<<"La cantidad de invocaciones recursiva fue de: "<<InvocacionesRecursivas<<endl;
        cout<<"Camino/Casillas recorridas: "<<ContCasillas<<endl;
        auto endtime=high_resolution_clock::now();
        duration<float,milli> duration= endtime-startTime;
        double finalTime= duration.count();
        cout<<finalTime/1000.0<<" segundos";
        tiempoAcumulado+=finalTime/1000;
        InvocacionesAcumuladas+=InvocacionesRecursivas;
        CaminoAcumulado+=ContCasillas;
    }

    return 0;

}


/*
        for(i ira de 0 hasta el la cantidad de k){
        TufuncionBakatraka(PArametros de tu funcion)
        mostrar matriz con solucion
        motrar metricas como tiempo de ejecucion, invocaciones recursivas y caminos recorridos
        }



*/
