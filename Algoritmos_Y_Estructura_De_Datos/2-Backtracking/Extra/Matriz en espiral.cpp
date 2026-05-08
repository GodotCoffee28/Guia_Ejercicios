#include<iostream>
using namespace std;

template<typename T>

void MostrarMatrizEspiral(T** matriz, int n, int m){
    int TotalElementos = n*m;
    int cont=0;
    int Izquierda = 0, Derecha = m-1, Arriba = 0, Abajo = n-1;
    
    while(Izquierda <= Derecha && Arriba <= Abajo){
        for(int j=Izquierda; j<=Derecha; j++){
            cout<<matriz[Arriba][j];
            cont++;
        }
        Arriba++;
        if(cont == TotalElementos) break;

        for(int i=Arriba; i<=Abajo; i++){
            cout<<matriz[i][Derecha];
            cont++;
        }
        Derecha--;
        if(cont == TotalElementos) break;
        

        if(Arriba <= Abajo){
        for(int j=Derecha; j>=Izquierda; j--){
            cout<<matriz[Abajo][j];
            cont++;
        }
        Abajo--;
        }
        if(cont == TotalElementos) break;

        if(Izquierda <= Derecha){
        for(int i=Abajo; i<=Arriba; i++){
            cout<<matriz[i][Izquierda];
            cont++;
        }
        Izquierda++;
        }
        if(cont == TotalElementos) break;

    }

}
template<typename T>
void MostrarMatriz(T** matriz, int n, int m){
    for(int i=0 ; i<n ; i++){ 
        for(int j=0; j<m; j++){
            cout<<" ("<<i<<","<<j<<") "<<matriz[i][j]<< " ";
        }
        cout<<"\n";
    }
    cout<<"\n\n----\n\n";
}

int main(){
int n;
int m;
cin>>n;
cin>>m;
    int** matriz;
    matriz = new int*[n];
    for(int i=0; i<n; i++) matriz[i] = new int[n];

    for(int i=0; i<n*n; i++) matriz[i/n][i%n] = i+1;

    char** Palabra;
    Palabra = new char*[n];

    for(int i=0; i<n; i++) Palabra[i] = new char[m];
    
    for(int i=0 ; i<n ; i++){ 
        for(int j=0; j<m; j++){
            cin>>Palabra[i][j];
        }

    }
    MostrarMatriz(Palabra, n, m);
    MostrarMatrizEspiral(Palabra, n, m);
    
    for(int i=0; i<n; i++){
        delete[] matriz[i];
    }
    delete[] matriz;
        for(int i=0; i<n; i++){
        delete[] Palabra[i];
    }
    delete[] Palabra;
        return 0;
}