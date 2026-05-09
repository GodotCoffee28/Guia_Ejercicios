#include<iostream>
#include<string>
using namespace std;

/*6. Genere todas las permutaciones posibles de un arreglo de caracteres de 
tamaño N. Ahora genere las permutaciones del mismo arreglo, asegurando que la suma sea un número par.*/
int contador=1;
void PermutacionesPosiblesEn(string Caracteres, int Tamanio, int indice){
    if(indice==Tamanio){
        int suma = 0;
        for(int i = 0; i < Tamanio; i++) suma+=Caracteres[i];
        if(suma % 2 == 0){ //Asegurandose que la suma sea impar, esto es bastante inutil pq en un arreglo no importa como ordenes la suma siempre será impar o par
            cout<<"PERMUTACION #"<<contador<<endl;
            cout<<Caracteres<<endl;
            contador++;
        }   
        return;
    }
    for(int i=indice; i<Tamanio; i++){
        
        swap(Caracteres[i], Caracteres[indice]);
        PermutacionesPosiblesEn(Caracteres, Tamanio, indice+1);
        swap(Caracteres[i], Caracteres[indice]);
    }

    return;
}
void swap(char *a, char *b){
    char aux= *a;
    *a=*b;
    *b= aux;
}



int  main(){
    string Caracteres="123456789";

    //cin>>Caracteres;
    PermutacionesPosiblesEn(Caracteres, Caracteres.length(), 0);

}