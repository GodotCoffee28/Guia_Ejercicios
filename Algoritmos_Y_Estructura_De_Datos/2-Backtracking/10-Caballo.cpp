#include<iostream>
using namespace std;

class Movimiento{
    public:
    int Fila;
    int Columna;
    Movimiento() : Fila(0), Columna(0){};
    Movimiento(int _Fila, int _Columna) : Fila(_Fila), Columna(_Columna){};

};

void MapearMovimientos(Movimiento Direcciones[]){
    Direcciones[0] =Movimiento(-2,1);
    Direcciones[1] =Movimiento(-1,2);
    Direcciones[2] =Movimiento(1,2);
    Direcciones[3] =Movimiento(2,1);
    Direcciones[4] =Movimiento(2,-1);
    Direcciones[5] =Movimiento(1,-2);
    Direcciones[6] =Movimiento(-1,-2);
    Direcciones[7] =Movimiento(-2,-1);
}
void ImprimirTablero(int **Tablero, int Tamano) {
    cout << "---------------------------------------" << endl;

    for (int i = 0; i < Tamano; i++) {
        for (int j = 0; j < Tamano; j++) {
            // Formateo para que los números se vean alineados
            if (Tablero[i][j] < 10) {
                cout << " | " << Tablero[i][j] << "| ";
            } else if (Tablero[i][j] < 100) {
                cout << " |" << Tablero[i][j] << "| ";
            } else {
                cout << "|" << Tablero[i][j] << "| ";
            }
        }
        cout << endl;
    }
    cout << "---------------------------------------" << endl;
}



bool RecorrerCasillas(Movimiento Caballo[], int Fila_Actual, int Colunma_Actual, int ContMov, int **Tablero, int Tamaño){
//Caso base, se a podido recorrer todas las casillas
    Tablero[Fila_Actual][Colunma_Actual]=ContMov;
    if(ContMov>=Tamaño*Tamaño){
        return true;
    }
        for(int i=0; i <8; i++){
            int SiguienteFila = Fila_Actual + Caballo[i].Fila;
            int SiguienteColunma= Colunma_Actual + Caballo[i].Columna;
            if(SiguienteFila < Tamaño && SiguienteColunma < Tamaño && SiguienteFila>=0 && SiguienteColunma>=0&& Tablero[SiguienteFila][SiguienteColunma]==0){

            if(RecorrerCasillas(Caballo, SiguienteFila, SiguienteColunma, ContMov+1, Tablero, Tamaño)){
                return true;
            }
            }
        }
    Tablero[Fila_Actual][Colunma_Actual] = 0;
    return false;
}

int  main(){
    Movimiento Caballo[8] = {Movimiento()};
    MapearMovimientos(Caballo);

    int N=8;

    //cin>>N;
    int **Tablero=new int*[N];
    for(int i=0; i<N; i++){
        Tablero[i] = new int[N]();
    }


    RecorrerCasillas(Caballo, 0, 0, 1, Tablero, N);

    ImprimirTablero(Tablero, N);
    
    for(int i=0; i<N; i++){
        delete[] Tablero[i];
    }
    delete[] Tablero;

    return 0;
}