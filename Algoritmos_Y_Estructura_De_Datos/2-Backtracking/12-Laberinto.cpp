#include <iostream>
using namespace std;

/*Una matriz bidimensional N x N puede representar un laberinto cuadrado. Cada posición contiene un entero no 
negativo que indica si la casilla es transitable (0) o si no lo es (1). Las casillas (1, 1) y (n, n) corresponden a la entrada 
y salida del laberinto y siempre son transitables. Dada una matriz con un laberinto, el problema consiste en diseñar un 
algoritmo que encuentre un camino, si existe, para ir de la entrada a la salida. Del mismo modo, consiga el camino de 
costo mínimo (menos casillas que recorrer).*/

bool EsPosicionValida(int i, int j, int N, int **Laberinto){
    return !(i > N - 1 || j > N - 1 || i < 0 || j < 0 ) && Laberinto[i][j] != 1;
}



// Arr Index = {Izquierda, Abajo, derecha, Arriba}


void ImprimirLaberinto(int **Laberinto, int n){
    for(int i=0; i<n;i++){
        for(int j=0; j<n;j++){
            cout<<"["<<Laberinto[i][j]<<"] ";
        }
        cout<<endl;
    }
}
int arrI[] = { 0, +1,  0, -1};
int arrJ[] = {-1,  0, +1,  0};
// 0 Fila_0 - Col_-1

int MIN_CASILLAS = 1000;

bool **Recorrido = new bool*[100];
void RecorrerLaberinto(int i_Actual, int j_Actual, int CantCasillasRecorridas, int **Laberinto, bool **Sendero,int n){
    if( i_Actual == n - 1  && j_Actual == n - 1){ //Caso base, encontramos la salida
        if(CantCasillasRecorridas < MIN_CASILLAS){
            MIN_CASILLAS = CantCasillasRecorridas;
            for(int i=0; i<n;i++){
                for(int j=0; j<n;j++){
                    Recorrido[i][j] = Sendero[i][j];
                }
            }
            Recorrido[n-1][n-1] = true;
        }
        return;
    }
    if( CantCasillasRecorridas > MIN_CASILLAS){ //Caso base, en caso de superar el minimo de casillas hasta el momento, ya ese camino no sirve
        return;
    }

    Sendero[i_Actual][j_Actual] = true; //Marco

    for(int i = 0; i < 4; i++){
        int Sig_i = i_Actual + arrI[i];
        int Sig_j = j_Actual + arrJ[i];
        if(EsPosicionValida(Sig_i, Sig_j, n, Laberinto) && !Sendero[Sig_i][Sig_j]){ //Para evitar movimientos q nos hagan volver, si ya estuvimos ahí no ir 
            RecorrerLaberinto(Sig_i, Sig_j,CantCasillasRecorridas+1, Laberinto, Sendero, n); // PASO RECURSIVO: Me muevo a la siguiente casilla y aumentamos 1 casilla
        }
    }
        Sendero[i_Actual][j_Actual] = false; //Desmarco
}



int main(){
    int Laberinto1[6][6] = {
        {0, 1, 1, 1, 1, 1},
        {0, 0, 0, 0, 1, 1},
        {1, 0, 0, 0, 0, 0},
        {0, 0, 1, 1, 1, 0},
        {0, 1, 0, 0, 0, 0},
        {0, 0, 0, 1, 1, 0}
    };
    int n = sizeof(Laberinto1[0])/sizeof(int);  
    int **Laberinto = new int*[n];
    for(int i=0; i<n; i++){
        Laberinto[i] = new int[n];
    }
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            Laberinto[i][j] = Laberinto1[i][j]; 
        }
    }
    
    bool **Sendero = new bool*[n];
    for(int i=0; i<n; i++){
        Sendero[i] = new bool[n]();
    }
    for(int i=0; i<n; i++){
        Recorrido[i] = new bool[n]();
    }
    
    //Camino por abajo, 15 casillas
    //Camino por la derecha, 11 casillas, el minimo
    ImprimirLaberinto(Laberinto, n);
    cout<<endl;
    RecorrerLaberinto(0,0,1, Laberinto, Sendero, n);

    cout<<"La cantidad minima de casillas para recorrer el laberinto fue: "<<MIN_CASILLAS<<endl;
    cout<<"Recorrido"<<endl;
    for(int i=0; i<n;i++){
        for(int j=0; j<n;j++){
            cout<<"["<<(Recorrido[i][j] ? 'X': ' ')<<"] ";
        }
        cout<<endl;
    }
    for(int i=0; i<n; i++){
        delete [] Laberinto[i]; 
    }
    delete[] Laberinto;
    for(int i=0; i<n; i++){
        delete [] Sendero[i]; 
    }
    delete[] Sendero;
    for(int i=0; i<n; i++){
        delete [] Recorrido[i]; 
    }
    delete[] Recorrido;
    return 0;
}