#include<iostream>
#include<string>
using namespace std;

class Objeto{
    public:
string Nombre;
int Peso;
int Valor;

Objeto(): Nombre(" "), Peso(0), Valor(0){}

Objeto(string _Nombre, int _Peso, int _Valor) : Nombre(_Nombre), Peso(_Peso), Valor(_Valor){}
};
// Cantidad de soluciones por la cantidad de objetos en una mochila
const int MAXSOLUCIONES = 500;
const int MAXOBJETOS = 8;
Objeto Soluciones[MAXSOLUCIONES][MAXOBJETOS] ={Objeto()};

int NSols=0;
void MiMochila(Objeto LaMochila[], int Tamaño, Objeto ObjetosDisponibles[], int cantidad, int ObjetoActual, int PesoActual, int PesoMaximo, Objeto Soluciones[][MAXOBJETOS], int indice=0){
    if(PesoActual>PesoMaximo){
        return;
    }
    if(ObjetoActual == cantidad){
        // Si al llegar aquí el peso actual no excede el máximo, esta es una solución válida.
        if (PesoActual <= PesoMaximo) {
            // Guardar esta solución si hay espacio en el arreglo global.
            if (NSols < MAXSOLUCIONES) { // ¡Cuidado con el desbordamiento!
                for(int i = 0; i < Tamaño; i++){
                    Soluciones[NSols][i] = LaMochila[i];
                }
                NSols++;
            }
        }
        return; // Terminamos esta rama de recursión.
    }



    int  ProximoPeso = PesoActual+ObjetosDisponibles[ObjetoActual].Peso;
    
    if(ProximoPeso<=PesoMaximo){
        if(indice<Tamaño){
        LaMochila[indice] = ObjetosDisponibles[ObjetoActual];

        MiMochila(LaMochila, Tamaño, ObjetosDisponibles, cantidad, ObjetoActual+1,ProximoPeso, PesoMaximo,Soluciones, indice+1);

        LaMochila[indice] = Objeto();
    }
    }

        MiMochila(LaMochila, Tamaño, ObjetosDisponibles, cantidad, ObjetoActual+1,PesoActual, PesoMaximo,Soluciones, indice);

    return;
}


int main(){

Objeto Mochila[MAXOBJETOS]={Objeto()};
Objeto Objetos[]={
    Objeto("Piedra", 12, 3),
    Objeto("Cuadernos", 15, 5),
    Objeto("Carpeta", 2, 1),
    Objeto("Laptop", 3, 15),
    Objeto("Cartera", 2, 1),
    Objeto("Cartuchera", 5, 7),
    Objeto("Peluche", 3, 6),
    Objeto("Almuerzo", 2, 7),
    Objeto("Cargador", 1, 5 ),
    Objeto("Taladro", 10, 15),
    Objeto("Mono", 1, 1)
};
int TamañoDeMochila = MAXOBJETOS;
int CantidadDeObjetos = sizeof(Objetos)/sizeof(Objetos[0]);
int PesoMaximo=30;
int PesoTotal=0, ValorTotal=0;
bool Solucion[10]={false};

MiMochila(Mochila, TamañoDeMochila ,Objetos, CantidadDeObjetos, 0, 0, PesoMaximo, Soluciones );
        int Sols=1;

    cout<<"\nSE HA HALLADO UNA SOLUCION\n";
    for(int i=0; i<NSols && NSols<=MAXSOLUCIONES; ++i){
        
        cout<<"_____SOLUCION #"<<Sols++<<"_____\n";
        PesoTotal=0, ValorTotal=0;
        for(int j=0; j<MAXOBJETOS;++j){
            if(Soluciones[i][j].Nombre!=" "){
        cout<<"Objeto #"<<j+1<<": "<<"Nombre: "<<Soluciones[i][j].Nombre<<"  Peso: "<<Soluciones[i][j].Peso<<" Valor: "<<Soluciones[i][j].Valor<<endl;
                PesoTotal+=Soluciones[i][j].Peso, ValorTotal+=Soluciones[i][j].Valor;
            }
        }
    cout<<"PESO TOTAL: "<<PesoTotal<<endl;
    cout<<"VALOR TOTAL: "<<ValorTotal<<endl;
    }
return 0;
}
