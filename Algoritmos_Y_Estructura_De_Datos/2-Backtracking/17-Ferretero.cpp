#include<iostream>
using namespace std;
/*Utilice la técnica de backtracking para resolver el siguiente problema: En una ferretería se venden segmentos de cable. 
Los clientes suelen pedir varios metros de cable, por lo que siempre quedan pedazos cortos de cable sin vender. 
Todos esos pedazos cortos van quedando sin ser vendidos en la ferretería,por lo que se ha decidido soldar todos los pedazos para vender 
cables repotenciados de 100 metros, a un precio razonablemente menor. El ferretero entiende que este problema es complejo,
pues tiene que tomar un conjunto que pedazos de cable que sumen exactamente 100 metros. El ferretero recurre a los estudiantes de AYED
para que le resuelvan su problema, que en resumen consiste en: dada las longitudes de cada uno de los N pedazos de cable existentes, 
indicar si se puede generar un cable de 100 metros, y en dado caso, saber qué segmentos de cable se soldaron para generar uno de 100
metros con la menor cantidad de soldaduras posibles, para mantener los bajos costos.*/
int n;
const int MAXSOLS = 10;
const int TAMAÑOSOLS= 10;
bool SOLUCIONES[MAXSOLS][TAMAÑOSOLS];
int CONTSOLS=0;
int MENORSOLDADURAS= INT_MAX;
int VUELTAS=0;
void GenerarCableDe100MejorSolucion(int* LargoDeCables, int cantidad, int LlegarA, int SumaActual, bool* CablesUsados, int ContSoldaduras, int CableActual){
    if(ContSoldaduras >= MENORSOLDADURAS){
    return;
    }
    if(SumaActual > LlegarA){
        return;
    }
    if(CableActual>= cantidad){
        return;
    }

    if(SumaActual==LlegarA){
        if(ContSoldaduras<=MENORSOLDADURAS){
        MENORSOLDADURAS=ContSoldaduras;
            for(int i=0; i<cantidad; i++){
                SOLUCIONES[0][i] = CablesUsados[i];
                CONTSOLS=-1;
            }
        }else{
            return;
        }
    }

    CablesUsados[CableActual] = true;
    GenerarCableDe100MejorSolucion(LargoDeCables, cantidad, LlegarA,SumaActual+LargoDeCables[CableActual],CablesUsados, ContSoldaduras+1, CableActual+1);
    CablesUsados[CableActual] = false;
    GenerarCableDe100MejorSolucion(LargoDeCables, cantidad, LlegarA, SumaActual, CablesUsados, ContSoldaduras, CableActual+1);
}

bool GenerarCableDe100PrimeraSolucion(int* LargoDeCables, int cantidad, int LlegarA, int SumaActual, bool* CablesUsados, int ContSoldaduras, int CableActual){

    if(SumaActual > LlegarA){//Si la suma de las longitudes de los cables supera a los 100 o los dados por ahi no es papi
        return false;
    }
    if(CableActual >= cantidad){
        return false;
    }

    if(SumaActual == LlegarA){ //Si la suma es exactamente al largo que quiero llegar guardo esa sol
        for(int i=0; i<cantidad; i++){
            SOLUCIONES[CONTSOLS][i] = CablesUsados[i];
        }
        MENORSOLDADURAS = ContSoldaduras;
        CONTSOLS++;
        return true;
        //return true; si retornamos ahi muere y solo almacena 1
    }
    //Un caso base para cuando la proxima solucion contenga mas soldaduras, si tiene mas soldaduras por ahi no es
    /*
    if(Contsoldaduras > MENORSOLDADURAS){
    return false;
    }
    */

if(!CablesUsados[CableActual]){
    SumaActual+= LargoDeCables[CableActual];
    CablesUsados[CableActual] = true;
    if(GenerarCableDe100PrimeraSolucion(LargoDeCables, cantidad, LlegarA, SumaActual,CablesUsados, ContSoldaduras+1, CableActual+1)){
        return true;
    }
    SumaActual-= LargoDeCables[CableActual];
    CablesUsados[CableActual] = false;
    if(GenerarCableDe100PrimeraSolucion(LargoDeCables, cantidad, LlegarA, SumaActual, CablesUsados, ContSoldaduras, CableActual+1)){
        return true;
    }
    }

return false;
}


void GenerarCableDe100(int* LargoDeCables, int cantidad, int LlegarA, int SumaActual, bool* CablesUsados, int ContSoldaduras, int CableActual){

    if(SumaActual > LlegarA){//Si la suma de las longitudes de los cables supera a los 100 o los dados por ahi no es papi
        return;
    }
    if(CableActual >= cantidad){
        return;
            
    }

    if(SumaActual == LlegarA){ //Si la suma es exactamente al largo que quiero llegar guardo esa sol
        for(int i=0; i<cantidad; i++){
            SOLUCIONES[CONTSOLS][i] = CablesUsados[i];
        }
        MENORSOLDADURAS = ContSoldaduras;
        CONTSOLS++;
        return;            //return true; si retornamos ahi muere y solo almacena 1
    }
    //Un caso base para cuando la proxima solucion contenga mas soldaduras, si tiene mas soldaduras por ahi no es
    /*
    if(Contsoldaduras > MENORSOLDADURAS){
    return false;
    }
    */

    CablesUsados[CableActual] = true;
    GenerarCableDe100(LargoDeCables, cantidad, LlegarA,SumaActual+LargoDeCables[CableActual],CablesUsados, ContSoldaduras+1, CableActual+1);
    CablesUsados[CableActual] = false;
    GenerarCableDe100(LargoDeCables, cantidad, LlegarA, SumaActual, CablesUsados, ContSoldaduras, CableActual+1);
}


int main() {
    //int n=7;
    //int* LargoDeCables = new int[n];
    //cout<<"Ingrese cuantos cables tiene: "<<endl;cin>>n;
    int LargoDeCables[] = {10, 5, 25, 15, 30, 40, 50, 55, 10, 100, 11, 23, 43, 21, 34, 56,43,22,11,34,20,21,34};
    for(int i=0; i<n; i++){
        cout<<"Ingrese el largo del cable #"<<i+1<<":"<<endl;
        cin>>LargoDeCables[i];
    }
    int CantidadCables = sizeof(LargoDeCables) / sizeof(LargoDeCables[0]);
    //int CantidadCables = n;
    bool* CablesUsados = new bool[CantidadCables]();

//    if(GenerarCableDe100MejorSolucion(LargoDeCables, CantidadCables, 100, 0, CablesUsados, 0, 0)){    }
    cout<<"Que desea?\n1-La primera solucion\n2-Todas las soluciones\n3-La mejor Solucion\n";
    int asd;
    cin>>asd;
    switch (asd)
    {
    case 1: GenerarCableDe100PrimeraSolucion(LargoDeCables, CantidadCables, 100, 0, CablesUsados, 0, 0);       break;
    case 2: GenerarCableDe100(LargoDeCables, CantidadCables, 100, 0, CablesUsados, 0, 0);       break;
    case 3: GenerarCableDe100MejorSolucion(LargoDeCables, CantidadCables, 100, 0, CablesUsados, 0, 0);     break;
    case 4: CONTSOLS=69 ; break;
    default:
    cout<<"maldito";
        break;
    }
    //GenerarCableDe100(LargoDeCables, CantidadCables, 100, 0, CablesUsados, 0, 0);
    //GenerarCableDe100PrimeraSolucion(LargoDeCables, CantidadCables, 100, 0, CablesUsados, 0, 0);
    //GenerarCableDe100MejorSolucion(LargoDeCables, CantidadCables, 100, 0, CablesUsados, 0, 0);
    
    if(CONTSOLS==1){
        cout<<"Se a encontrado almenos una solucion para su problema, ferretero!"<<endl;
        for(int i=0; i<CantidadCables; i++){
            if(SOLUCIONES[0][i]){
                cout<<"Cable #"<<i+1<<" De largo: "<<LargoDeCables[i]<<endl;
            }
        }
    }else if(CONTSOLS>1){
        cout<<"Se han encontrado multiples SOLUCIONES para su problema, ferretero!"<<endl;
        for(int i=0; i<CONTSOLS; i++){
            int Suma=0;
            cout<<"----SOLUCION #"<<i+1<<"----"<<endl;
            for(int j=0; j<CantidadCables; j++){
                if(SOLUCIONES[i][j]){
                    cout<<"Cable #"<<j+1<<" De largo: "<<LargoDeCables[j]<<endl;
                    Suma+=LargoDeCables[j];
                }
            }
            cout<<"Suma de longitudes: "<<Suma<<endl;
        }
    }else if(CONTSOLS==-1){
        cout<<"Se a encontrado LA MEJOR SOLUCION  para su problema, ferretero!"<<endl;
        for(int i=0; i<CantidadCables; i++){
            if(SOLUCIONES[0][i]){
                cout<<"Cable #"<<i+1<<" De largo: "<<LargoDeCables[i]<<endl;
            }
        }
    }else if(CONTSOLS==0){
        cout<<"No se ha encontrado ninguna solucion para su problema con los cables dados, ferretero"<<endl;
    }else if(CONTSOLS==69){
        CONTSOLS=0;
        GenerarCableDe100PrimeraSolucion(LargoDeCables, CantidadCables, 100, 0, CablesUsados, 0, 0);
        cout<<"Se a encontrado almenos una solucion para su problema, ferretero!"<<endl;
        for(int i=0; i<CantidadCables; i++){
            if(SOLUCIONES[0][i]){
                cout<<"Cable #"<<i+1<<" De largo: "<<LargoDeCables[i]<<endl;
            }           
        }
        CONTSOLS=0;
        GenerarCableDe100(LargoDeCables, CantidadCables, 100, 0, CablesUsados, 0, 0);
        cout<<"Se han encontrado multiples SOLUCIONES para su problema, ferretero!"<<endl;
        for(int i=0; i<CONTSOLS; i++){
            int Suma=0;
            cout<<"----SOLUCION #"<<i+1<<"----"<<endl;
            for(int j=0; j<CantidadCables; j++){
                if(SOLUCIONES[i][j]){
                    cout<<"Cable #"<<j+1<<" De largo: "<<LargoDeCables[j]<<endl;
                    Suma+=LargoDeCables[j];
                }
            }
            cout<<"Suma de longitudes: "<<Suma<<endl;
        }
        CONTSOLS=0;
        GenerarCableDe100MejorSolucion(LargoDeCables, CantidadCables, 100, 0, CablesUsados, 0, 0);
        cout<<"Se a encontrado LA MEJOR SOLUCION  para su problema, ferretero!"<<endl;
        for(int i=0; i<CantidadCables; i++){
            if(SOLUCIONES[0][i]){
                cout<<"Cable #"<<i+1<<" De largo: "<<LargoDeCables[i]<<endl;
            }
        }
    }

    delete[] CablesUsados;
    return 0;
}