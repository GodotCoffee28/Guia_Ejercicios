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



void MiMochila(Objeto LaMochila[], int Tamaño, Objeto ObjetosDisponibles[], int cantidad, int ObjetoActual, int PesoActual, int PesoMaximo, bool Solucion[], int indice=0){
    if(PesoActual>PesoMaximo){
        return;
    }else if(PesoActual==PesoMaximo){
        return;
    }
    if(ObjetoActual==cantidad){
        return;
    }
    LaMochila[indice] = ObjetosDisponibles[ObjetoActual];
    PesoActual+=LaMochila[indice].Peso;
    Solucion[ObjetoActual] = true;
    if(PesoActual<=PesoMaximo&&Solucion[ObjetoActual]){
        MiMochila(LaMochila, Tamaño, ObjetosDisponibles, cantidad, ObjetoActual+1,PesoActual, PesoMaximo,Solucion, indice+1);
    }else{
    PesoActual-=LaMochila[indice].Peso;
    LaMochila[indice] = Objeto();
    Solucion[ObjetoActual] = false;
            MiMochila(LaMochila, Tamaño, ObjetosDisponibles, cantidad, ObjetoActual+1,PesoActual, PesoMaximo,Solucion, indice);
    }





    return;
}


int main(){

Objeto Mochila[6]={Objeto()};
Objeto Objetos[10]={
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
};
int PesoTotal=0, ValorTotal=0;
bool Solucion[10]={false};

MiMochila(Mochila, 6,Objetos, 10, 0, 0, 30, Solucion );
    cout<<"\nSE HA HALLADO UNA SOLUCION\n";
    for(int i=0; i<6; ++i){
        cout<<"Objeto #"<<i+1<<":\n"<<"Nombre: "<<Mochila[i].Nombre<<"  Peso: "<<Mochila[i].Peso<<" Valor: "<<Mochila[i].Valor<<endl;
        PesoTotal+=Mochila[i].Peso, ValorTotal+=Mochila[i].Valor;
    }
    cout<<"PESO TOTAL: "<<PesoTotal<<endl;
    cout<<"VALOR TOTAL: "<<ValorTotal<<endl;





return 0;
}