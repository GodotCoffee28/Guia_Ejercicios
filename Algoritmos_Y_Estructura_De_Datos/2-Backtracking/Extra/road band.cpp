#include<iostream>
#include<math.h>
using namespace std;

int m, n, k;
float s;

struct Punto{
    float x;
    float y;
    Punto(): x(0), y(0){};
    Punto(float _x, float _u): x(_x), y(_u){};
};
Punto* CoordenadasClientes;
Punto* Routers;


void EntraDatos(int &m, int &n, int &k, int &s);
void Ubicaciones(int m, int n, int k, int s);

bool EsValida(int d);
bool ComprobarParametros(int m, int n, int k, int s);
//m cantidad de clientes en la calle de arriba, n cantidad de clientes en la calle de abajo
//k minima cantidad de routers  distancia que separa a las calles
void EntradaDatos(int &m, int &n, int &k, float &s){ 
    do{
    cout<<"Ingrese la cantidad de  clientes de la calle de arriba 'm' entre 1 a 1000:  "<<endl; cin>>m;
    cout<<"Ingrese la cantidad de  clientes de la calle de abajo 'n' entre 1 a 1000:  "<<endl; cin>>n;
    cout<<"Ingrese la minima cantidad de routers 'k':  "<<endl; cin>>k;
    cout<<"Ingrese la distancia que separa a las calles 's' entre 1 a 50:  "<<endl; cin>>s;
    if(!ComprobarParametros(m, n, k, s)){
        cout<<"Error, Ingrese parametros en el rango de numeros especificado"<<endl;
    }
    }while(!ComprobarParametros(m, n, k, s));


}

void Ubicaciones(int m, int n, int k, float s){

CoordenadasClientes = new Punto[m+n];

    for(int i=0; i<m+n; i++){
        if(i<=m){
    int aux;
    cin>>aux; 
    if(!EsValida(aux)) {cout<<"Maldito"; return;}
    CoordenadasClientes[i] = Punto(aux, s);
        }else{
    int aux;
    cin>>aux; 
    if(!EsValida(aux)) {cout<<"Maldito"; return;}
    CoordenadasClientes[i] = Punto(aux, 0);
        }
    }
  for(int i=0; i<m+n; i++){
        cout<<"Cliente #"<<i+1<<" en las coordenadas ("<<CoordenadasClientes[i].x<<" , "<<CoordenadasClientes[i].y<<")\n";
    }
}
bool EsValida(int d){
    return d >= 0 && d <= 1000;
}

bool ComprobarParametros(int m, int n, int k, int s){
        return (m >=1 && m <= 1000) && (n >=1 && n <= 1000) && (k >=1 && k <= min(max(m,n), 100)) && (s>=1 && s<=50); 
}
int MinSumaDistancia = 1000;
int CalcularDistancias(Punto* CoordsClients, int* Rpos, int SumaDistancias){
    if(SumaDistancias >= MinSumaDistancia){
        return -1;
    }
    if(SumaDistancias < MinSumaDistancia){
        MinSumaDistancia = SumaDistancias;
        return SumaDistancias;
    } 
    
    return 0;
}

//Suma de la distancia cuadrada entre un router con el cliente sera la ubicacion en x del router XR menos la ubicacion en x del cliente XR-XC todo esto al cuadrado

int main(){
EntradaDatos(m, n, k, s);
Routers = new Punto [k];
for(int i=0; i<k; i++) Routers[i] = Punto(0,s/2);
for(int i=0; i<k; i++){ 
    cout<<"Router #"<<i+1<<" en ("<<Routers[i].x<<" , "<<Routers[i].y<<")\n";}
Ubicaciones(m, n, k, s);

    return 0;
}