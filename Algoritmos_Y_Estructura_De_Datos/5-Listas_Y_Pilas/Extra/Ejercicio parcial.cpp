#include<iostream>
using namespace std;


template<typename T>
class Inventario{
    public:
    struct Objeto{
        int Tipo;
        int Peso;
        Objeto* Siguente;
        Objeto(int t, int p, Objeto* s=nullptr): Tipo(t), Peso(p), Siguente(s){}
    };
    public:
    typedef Objeto* Nodo;
    Objeto* Frente;
    Objeto* Cola;
    int CantidadObjetos;

    Inventario(): CantidadObjetos(0){
        Cola = new Objeto(0,0);
        Frente = new Objeto(0,0, Cola);
    }
    Inventario(const Inventario &inventario){
        agregar(inventario);
    }
    int CantidadObjets(){
        return CantidadObjetos;
    }

    bool EstaVacio(){
        return CantidadObjetos==0;
    }
    void Siguiente(Objeto pObjeto){
        if(pObjeto != Cola){
            pObjeto = pObjeto->Siguente;
        }
    }
    int& ObtenerTipo(Objeto pObjeto){
        return pObjeto->Tipo;
    }
    int& ObtenerPeso(Objeto pObjeto){
        return pObjeto->Peso;
    }

    Nodo Primero(){
        return (Frente->Siguente != Cola) ? Frente->Siguente:Cola; 
    }

    void agregar(Objeto elemento){
        if(EstaVacio()){
            Frente->Siguente = elemento;
            elemento->Siguente = Cola;
            CantidadObjetos++;
            return;
        }
        Nodo Actual = Primero();
        while(Actual->Siguente != Cola){
            Siguiente(Actual);
        }
        Actual->Siguente = new Objeto(ObtenerTipo(elemento),ObtenerPeso(elemento), Cola);
        CantidadObjetos++;
    }

    void agregar(Inventario inventario){
            Nodo Actualotro = inventario.Primero();
            while(Actualotro->Siguente != inventario->Cola){
                agregar(Actualotro);
                Siguiente(Actualotro);
            }
            CantidadObjetos = inventario.CantidadObjets();
    }
    void eliminar(Objeto Objeto){
        Nodo Actual = Primero();
        while(Actual->Siguente != Objeto){
            Siguiente(Actual);
        }
        Actual->Siguente = Objeto->Siguente;
        delete Objeto;
        CantidadObjetos--;
    }
    int pesoTotal(){
        Nodo Actual = Primero();
        int PesoTotal = 0;
        while(Actual->Siguente != Cola){
            PesoTotal+= ObtenerPeso(Actual);
        }
        return PesoTotal;
    }


};

int main(){
    cout<<"Cualquier vaina hablame";
    Inventario<int> MiInventario;
    Objeto Objetos = new Objeto(1, 2 ,3)
    MiInventario.agregar()
    
        //List<Objeto> objetos();
    return 0;
}