#include<iostream>
using namespace std;

 const int N=5;
void ImprimirFabrica(int Fabrica[N][N]);
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

 //El de las bombillas

bool EstaIluminada(int Fabrica[N][N]){
for(int i=0; i<N; i++){
    for(int j=0; j<N; j++){
        if( Fabrica[i][j]==0) return false;
    }
}
    return true;
}


 void PonerLuz(int Fabrica[N][N],int Fila, int Col){ //N=5 Fila=4
    if(Fila>0)          Fabrica[Fila-1][Col] =3;
    if(Fila<N-1)         Fabrica[Fila+1][Col] = 3;
    if(Col>0)         Fabrica[Fila][Col-1] =3;
    if(Col<N-1)         Fabrica[Fila][Col+1] = 3;
    if(Fila>0 && Col>0)         Fabrica[Fila-1][Col-1] =3;
    if(Fila<N-1 && Col<N-1)         Fabrica[Fila+1][Col+1] = 3;
    if(Fila>0 && Col<N-1)         Fabrica[Fila-1][Col+1] =3;
    if(Fila<N-1&& Col>0)         Fabrica[Fila+1][Col-1] = 3;
}
void QuitarLuz(int Fabrica[N][N], int Fila, int Col){
        if(Fila>0)          Fabrica[Fila-1][Col] =0;
    if(Fila<N-1)         Fabrica[Fila+1][Col] = 0;
    if(Col>0)         Fabrica[Fila][Col-1] =0;
    if(Col<N-1)         Fabrica[Fila][Col+1] = 0;
    if(Fila>0 && Col>0)         Fabrica[Fila-1][Col-1] =0;
    if(Fila<N-1 && Col<N-1)         Fabrica[Fila+1][Col+1] = 0;
    if(Fila>0 && Col<N-1)         Fabrica[Fila-1][Col+1] =0;
    if(Fila<N-1&& Col>0)         Fabrica[Fila+1][Col-1] = 0;

}

int MenorCantidadBombillos = 100;

bool Eseguro(int Fabrica[N][N], int Fila, int Col){
if(Fila>0&&Fabrica[Fila-1][Col] !=0)return false;
if(Fila<N-1&&Col<N-1&&Fabrica[Fila+1][Col] !=0 )return false;
if(Col>0&&Col<N-1&&Fabrica[Fila][Col-1] !=0)return false;
if(Col<N-1&&Fabrica[Fila][Col+1] !=0)return false;
if(Fila>0 && Col>0&&Fabrica[Fila-1][Col-1] !=0)return false;
if(Fila<N-1 && Col<N-1&& Fabrica[Fila+1][Col+1] !=0)return false;
if(Fila>0 && Col<N-1&&Fabrica[Fila-1][Col+1] !=0)return false;
if(Fila<N-1&& Col>0&&Col<N-1&&Fabrica[Fila+1][Col-1] !=0)return false;

return true;
}

int Bombillas(int Fabrica[N][N],Movimiento Mov[], int FilaActual, int ColActual, int ContBomb){

if(EstaIluminada(Fabrica)) return ContBomb; //caso base cuando toda la fabrica tiene luz
//Proceso de marcado
        if(Eseguro(Fabrica, FilaActual, ColActual)){
            Fabrica[FilaActual][ColActual] =2;
            PonerLuz(Fabrica, FilaActual, ColActual);
            ImprimirFabrica(Fabrica);
            Bombillas(Fabrica, Mov, FilaActual, ColActual, ContBomb+1);
            Fabrica[FilaActual][ColActual] = 0;
            QuitarLuz(Fabrica, FilaActual, ColActual);
        }


return ContBomb;
}

void ImprimirFabrica(int Fabrica[N][N]){
    
        for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(Fabrica[i][j]==2) cout<<"O ";
            if(Fabrica[i][j]==3) cout<<"* ";
            if(Fabrica[i][j]==0) cout<<". ";
        }
        cout<<endl;
    }
    cout<<"______________________________________________________________________"<<endl;
}
Movimiento Mov[4];


int main(){
    int Matriz[N][N];
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            Matriz[i][j] =0; 
    }
}
inicializarMovimientosDireccionales(Mov);
int Cuanto=Bombillas(Matriz,Mov, 0, 0, 0);
cout<<"Bombillos usados: "<<Cuanto<<endl;
ImprimirFabrica(Matriz);

    return 0;
}

