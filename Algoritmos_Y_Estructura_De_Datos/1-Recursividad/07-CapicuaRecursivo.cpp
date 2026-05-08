#include <iostream>
#include<string>
using namespace std;

int Escapicua(string Palabra, int Inicio, int Fin);
/*Elabore una función recursiva la cual dado un arreglo de caracteres que
forman una palabra retorne verdadero si ésta es capicúa. Ejemplos palabras capicúas: salas, oro, arepera.*/

int main(){
    string Palabra;

    cout<<"Introduzca su palabra: "<<endl; cin>>Palabra;
    int inicio=0;
    int fin = Palabra.length() - 1;
    
    if(Escapicua(Palabra, inicio, fin)){
        cout<<"Es capicua"<<endl;
    }else{
        cout<<"No es capicua"<<endl;       
    }

    return 0;
}

int Escapicua(string Palabra, int Inicio, int Fin){
    if(Inicio==Fin||Inicio>=Fin) return 1;
    else if(Palabra[Inicio]==Palabra[Fin]) return Escapicua(Palabra, Inicio+1, Fin-1);
        else return 0;
}