#include<iostream>
using namespace std;

/*8. Dado un entero N, imprimir todas las expresiones aritméticas compuestas por los operadores +, - , * y /, y los 
primeros N números naturales en orden en la cual el resultado sea igual a un R dado. El orden de prioridad es de 
izquierda a derecha. Ejemplo: Para N=4 y R=0, algunas expresiones podrían ser: -1 -2 +3 * 4 = 0, +1 +2 -3 *4 = 0 */


const int SUMA = 1;
const int RESTA = 2;
const int MULTIPLICACION = 3;
const int DIVISION = 4;
int AplicarOperador(int PrimerNumero, int SegundoNumero, int Operacion){
    switch (Operacion)
    {
    case SUMA:   return PrimerNumero + SegundoNumero;
    case RESTA: return PrimerNumero - SegundoNumero;
    case MULTIPLICACION: return PrimerNumero * SegundoNumero;
    case DIVISION: return PrimerNumero / SegundoNumero;

    default: return 0;
    }
}

char ObtenerOperador(int Operador){
    switch (Operador){
    case SUMA:   return  '+';
    case RESTA: return  '-';
    case MULTIPLICACION: return  '*';
    case DIVISION: return '/';

    default: return ' ';
    }
}
void MostrarSolucion(int N, int R,int *OperacionesUsadas,int &IndexSoluciones){
    IndexSoluciones++;
    cout<<"#"<<IndexSoluciones<<" ";
    cout<<ObtenerOperador(OperacionesUsadas[0])<<" ";
    for(int i=1; i < N; i++){
        cout<<i<<" ";
        cout<<ObtenerOperador(OperacionesUsadas[i])<<" ";
    }
    cout<<N<<" = "<<R<<endl;
}


void ExpresionesAritmeticas(int N, int R, int *OperacionesUsadas,int &IndexSoluciones,int N_actual = 1, int R_acumulado = 0){
    if(N_actual > N ){
        if(R_acumulado != R){
            return;
        }
        MostrarSolucion(N, R_acumulado, OperacionesUsadas, IndexSoluciones);
        return;
    }
    if(N_actual == 1){
        int N_Siguiente = N_actual + 1;
        OperacionesUsadas[0] = SUMA; //Marcamos SUMA
        ExpresionesAritmeticas(N, R, OperacionesUsadas,IndexSoluciones, N_Siguiente, N_actual);
        OperacionesUsadas[0] = RESTA; //Desmarcamos Suma y marcamos Resta
        ExpresionesAritmeticas(N, R, OperacionesUsadas,IndexSoluciones, N_Siguiente, -N_actual);
        OperacionesUsadas[0] = 0; //Desmarcamos Resta
    }else{
        for(int i_Operador = 0; i_Operador < 4; i_Operador++){
            int OperadorActual = i_Operador + 1; // SUMA, RESTA, MULTIPLICACION o DIVISION
            OperacionesUsadas[N_actual - 1] = OperadorActual;  // MARCAMOS en la posicion del indice de operadores el operador actual
            int N_Siguiente = N_actual + 1;
            ExpresionesAritmeticas(N, R, OperacionesUsadas,  IndexSoluciones, N_Siguiente,AplicarOperador( R_acumulado, N_actual, OperadorActual));
            OperacionesUsadas[N_actual - 1] = 0; //DESMARCAMOS
        }
    }



}



int main(){
    int N;
    do{
        cout<<"Introduzca su N > 0: "; cin>>N; cout<<"\n";
        if( N <= 0) cout<<"Su N tiene que ser > 0"<<endl;
    }while(N <= 0);
    int R;
    cout<<"Introduzca su R: "; cin>>R; cout<<"\n";

    int *OperacionesUsadas = new int[N](); // si tienes N numeros, habrá N operadores (contando el unario o signo del -1 o +1)
    int IndexSoluciones = 0;

    ExpresionesAritmeticas(N, R, OperacionesUsadas, IndexSoluciones);
    if(!IndexSoluciones){
        cout<<"Lo siento, no se encontraron soluciones."<<endl;
    }
    delete[] OperacionesUsadas;
    return 0;
}
