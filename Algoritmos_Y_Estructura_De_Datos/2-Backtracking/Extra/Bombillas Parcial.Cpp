#include<iostream>
using namespace std;

const int OSCURO=0;
const int OBSTACULO=1;
const int BOMBILLO=2;
const int ILUMINADO=3;

const int N=3;
const int F[]{-1, -1, -1, 0, 1, 1,  1,  0 };
const int C[]{-1,  0,  1, 1, 1, 0, -1, -1 };
int Iluminacion[N][N]{0};

void PonerLuz(int Fabrica[N][N],int FilaAc, int ColAc);
void QuitarLuz(int Fabrica[N][N],int FilaAc, int ColAc);
bool FabricaIluminada(int Fabrica[N][N]);
bool EsSeguroPoner(int Fabrica[N][N], int Fila, int Col );
int Bombillas(int Fabrica[N][N],int ContadorDeBombillas, int MinBombillas, int idx);
void ImprimirFabrica(int Fabrica[N][N], int Min);
 /*void PonerLuz(){ //N=5 Fila=4
    if(Fila > 0     && EsSeguroPoner(Fabrica, Fila-1, Col))         Fabrica[Fila-1][Col] = ILUMINADO, Iluminacion[Fila-1][Col]++;
    if(Fila < N - 1 && EsSeguroPoner(Fabrica, Fila+1, Col))         Fabrica[Fila+1][Col] = ILUMINADO, Iluminacion[Fila+1][Col]++;
    if(Col > 0      && EsSeguroPoner(Fabrica, Fila, Col-1))         Fabrica[Fila][Col-1] = ILUMINADO, Iluminacion[Fila][Col-1]++;
    if(Col < N - 1  && EsSeguroPoner(Fabrica, Fila, Col+1))         Fabrica[Fila][Col+1] = ILUMINADO, Iluminacion[Fila][Col+1]++;
    if(Fila >0 && Col > 0          && EsSeguroPoner(Fabrica, Fila-1, Col-1))         Fabrica[Fila-1][Col-1] = ILUMINADO, Iluminacion[Fila-1][Col-1]++;
    if(Fila < N - 1 && Col < N - 1 && EsSeguroPoner(Fabrica, Fila+1, Col+1))         Fabrica[Fila+1][Col+1] = ILUMINADO, Iluminacion[Fila+1][Col+1]++;
    if(Fila > 0 && Col < N - 1     && EsSeguroPoner(Fabrica, Fila-1, Col+1))         Fabrica[Fila-1][Col+1] = ILUMINADO, Iluminacion[Fila-1][Col+1]++;
    if(Fila < N - 1 && Col > 0     && EsSeguroPoner(Fabrica, Fila+1, Col-1))         Fabrica[Fila+1][Col-1] = ILUMINADO, Iluminacion[Fila+1][Col-1]++;
}
 void QuitarLuz(int Fabrica[N][N],int Fila, int Col){ //N=5 Fila=4
    if(Fila > 0     && EsSeguroPoner(Fabrica, Fila-1, Col)){ Iluminacion[Fila-1][Col]--; if(Iluminacion[Fila-1][Col]==0){Fabrica[Fila-1][Col] = OSCURO;}}
    if(Fila < N - 1 && EsSeguroPoner(Fabrica, Fila+1, Col)){ Iluminacion[Fila+1][Col]--; if(Iluminacion[Fila+1][Col]==0)}         Fabrica[Fila+1][Col] = OSCURO, ;
    if(Col > 0      && EsSeguroPoner(Fabrica, Fila, Col-1)){}         Fabrica[Fila][Col-1] = OSCURO, Iluminacion[Fila][Col-1]--;
    if(Col < N - 1  && EsSeguroPoner(Fabrica, Fila, Col+1)){}         Fabrica[Fila][Col+1] = OSCURO, Iluminacion[Fila][Col+1]--;
    if(Fila >0 && Col > 0          && EsSeguroPoner(Fabrica, Fila-1, Col-1)){}         Fabrica[Fila-1][Col-1] = OSCURO, Iluminacion[Fila-1][Col-1]--;
    if(Fila < N - 1 && Col < N - 1 && EsSeguroPoner(Fabrica, Fila+1, Col+1)){}         Fabrica[Fila+1][Col+1] = OSCURO, Iluminacion[Fila+1][Col+1]--;
    if(Fila > 0 && Col < N - 1     && EsSeguroPoner(Fabrica, Fila-1, Col+1)){}         Fabrica[Fila-1][Col+1] = OSCURO, Iluminacion[Fila-1][Col+1]--;
    if(Fila < N - 1 && Col > 0     && EsSeguroPoner(Fabrica, Fila+1, Col-1)){}         Fabrica[Fila+1][Col-1] = OSCURO, Iluminacion[Fila+1][Col-1]--;
}*/

void PonerLuz(int Fabrica[N][N],int FilaAc, int ColAc){ //Colocar la luz alrededor de una posicion
    Iluminacion[FilaAc][ColAc]++; //La posicion en la que estamos la iluminamos, donde esta el bombillo colocado
    for(int i=0; i<8; i++){//Iteramos en los8 vecinos
        int FilaVe = FilaAc + F[i]; //Fila vecina
        int ColVe = ColAc + C[i]; //Columna vecina
        if(FilaVe >= 0 && FilaVe < N && ColVe >= 0 && ColVe < N){ //verificamos que este dentro de los limites esa fila y columna vecina
            if(EsSeguroPoner(Fabrica, FilaVe, ColVe)){ //Se verifica que no haya ningun elemento que no sea oscuro
                Fabrica[FilaVe][ColVe] = ILUMINADO; //Iluminamos los vecinos
            }
    Iluminacion[FilaVe][ColVe]++;//Aumentamos el nivel de iluminacion
        }
    }
}
void QuitarLuz(int Fabrica[N][N],int FilaAc, int ColAc){//Quitar la luz alrededor de una posicion
    Iluminacion[FilaAc][ColAc]--; // La posicion en la que estamos le quitamos un nivel de luz, donde esta el bombillo colocado
    for(int i=0; i<8; i++){//Iteramos en los 8 vecinos
        int FilaVe = FilaAc + F[i]; //Fila vecina
        int ColVe = ColAc + C[i]; //Columna vecina
        if(FilaVe >= 0 && FilaVe < N && ColVe >= 0 && ColVe < N){ //verificamos que este dentro de los limites esa fila y columna vecina
            Iluminacion[FilaVe][ColVe]--; //Le bajamos un nivel de iluminacion igulamente
            if(Iluminacion[FilaVe][ColVe] == 0 && Fabrica[FilaVe][ColVe] == ILUMINADO){ //si el nivel de iluminacion llega a 0 y ese vecino esta iluminado
                Fabrica[FilaVe][ColVe] = OSCURO; //Se apaga o se quita la luz
            }
        }
    }
}



bool FabricaIluminada(int Fabrica[N][N]){ // Se usa para verificar que toda la fabrica esta iluminada
    for(int i=0; i<N; ++i){
        for(int j=0; j<N; ++j){
            if(Fabrica[i][j] == OSCURO && Fabrica[i][j] != OBSTACULO) return false; //si la fabrica esta oscura y no es un obstaculo en esa posicion entonces no esta iluminada totalmente
        }
    }
    return true; //si no encuentra una posicion oscura signifca que esta iluminada completamente
}

bool EsSeguroPoner(int Fabrica[N][N], int Fila, int Col ){//Verificamos que la posicion en la fabrica no es ni un obstaculo, un bombillo o iluminacion
    return !(Fabrica[Fila][Col] == OBSTACULO || Fabrica[Fila][Col] == BOMBILLO || Fabrica[Fila][Col] == ILUMINADO); //si se consigue algo de lo anterior es verdad y con la negacion decimos que no es seguro
}
int MinBombillasGlobal=1000; //Minima cantidad de bombillas
int Bombillas(int Fabrica[N][N],int ContadorDeBombillas, int MinBombillas, int idx){ //Funcion Backtraking
    if(ContadorDeBombillas >= MinBombillasGlobal){  //Condicion de poda: Si el contador de bombillas en esa ramba supera la global no vale la pena seguir esa rama
        return -1; //-1 porque no se halló resultado
    }
    if(FabricaIluminada(Fabrica)){ //Caso base: Si la fabrica esta totalmente iluminada
        if(ContadorDeBombillas < MinBombillasGlobal){ //Y si el contador de bombillas es menor que el minimo de bombillas globales o el mejor
            MinBombillasGlobal=ContadorDeBombillas; //se cambia el mejor por esta rama
                        ImprimirFabrica(Fabrica, ContadorDeBombillas); //se imprime ese resultado
        }

        return ContadorDeBombillas;//Retornamos la cantidad de bombillas de esta rama
    }
    if(idx == N*N){ //Si idx que es la forma en la que nos movemos en la matriz, es igual a N*N que es el total de casillas, significa que se recorrio toda la fabrica y hay partes sin iluminar
        return -1; //Esta rama no es prometedora

    }
//Interesante, para calcular una fila y una columna manejando un solo indice recorremos la matriz de forma lineal
/* 0   1   2   3   4   <-- Fila 0
5   6   7   8   9   <-- Fila 1
10  11  12  13  14   <-- Fila 2
15  16  17  18  19   <-- Fila 3
20  21  22  23  24   <-- Fila 4
Donde idx esta se divide y obtenemos la fila, y se modea para sacar la colunma idx / N = Fila, idx % N = Columna
*/
int FilaActual = idx/N, ColActual = idx%N; //obtenemos la fila y colunma actual
int Resultado1Pongo=-1; //Inicializamos el resultado de poner
int Resultado2No=-1; //Inicializamos el de no poner


if(EsSeguroPoner(Fabrica, FilaActual, ColActual)){ //Comprobamos que si la posicion actual es seguro poner un bombillo
    //Proceso de marcado
    Fabrica[FilaActual][ColActual] = BOMBILLO;//Poner bombillo
    PonerLuz(Fabrica, FilaActual, ColActual); //Iluminar alrededor
    Resultado1Pongo = Bombillas(Fabrica, ContadorDeBombillas+1, MinBombillasGlobal, idx+1); //llamada recursiva, Exploramos la siguiente posicion en la matriz con idx+1 y como pusimos un bombillo aumentamos el contador
    //Proceso de desmarcado / Backtrack
    QuitarLuz(Fabrica, FilaActual, ColActual);  //quitamos la luz (Como en mi barrio)
    Fabrica[FilaActual][ColActual] = OSCURO; //quitamos el bombillo
}
Resultado2No = Bombillas(Fabrica, ContadorDeBombillas, MinBombillasGlobal, idx+1); //El resultado2No es cuando no ponemos el bombillo y avanzamos de posicion

int Resultado3Final=-1; //Resultado final de la rama
if(Resultado1Pongo!=-1){ //Si tenemos un resultado en esa rama
    Resultado3Final = Resultado1Pongo; //La obtenemos como la final
}
if(Resultado2No!=-1){ //Si tenemos un resultado en la rama de no poner
    if(Resultado3Final == -1 ||  Resultado2No < Resultado3Final){ //Y si El resultado final no fue actualizado o el resutado de no  poner es menor que el resultado de final (Minimca cantidad de bombillos)
        Resultado3Final = Resultado2No; //la remplazamos como la minima o la mejor
    }
}
 return Resultado3Final; //Lo regresamos al final
}

void ImprimirFabrica(int Fabrica[N][N], int Min){ //Mostrar el estado actual de la fabrica
        cout<<"La cantidad minima de bombillas para tu fabrica es de: "<<Min<<endl;
    for(int i=0; i<N; i++){
        for(int j=0; j<N; j++){
            if(Fabrica[i][j]==OSCURO) cout<<". ";
            if(Fabrica[i][j]==BOMBILLO) cout<<"B ";
            if(Fabrica[i][j]==OBSTACULO) cout<<"| ";
            if(Fabrica[i][j]==ILUMINADO) cout<<"* ";
        }
        cout<<endl;
    }
    cout<<"_____________________________________________________"<<endl;
}



int main(){
    int Fabrica[N][N]{0};
    int MinBombillas=1000;
    int Min = Bombillas(Fabrica, 0, MinBombillasGlobal, 0);
    return 0;
}