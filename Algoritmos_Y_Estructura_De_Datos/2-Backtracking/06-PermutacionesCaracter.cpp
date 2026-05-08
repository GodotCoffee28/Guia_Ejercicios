#include<iostream>
#include<string>
using namespace std;

/*Genere todas las permutaciones posibles de un arreglo de caracteres de 
tamaño N. Ahora genere las permutaciones del mismo arreglo, asegurando que la suma sea un número par.*/
int contador=1;
void PermutacionesPosiblesEn(string Caracteres, int Tamaño, int indice){
    if(indice==Tamaño){
            
        cout<<"PERMUTACION #"<<contador<<endl;
        cout<<Caracteres<<endl;
        contador++;
        return;
    }
    for(int i=indice; i<Tamaño; i++){
        
        swap(Caracteres[i], Caracteres[indice]);
        PermutacionesPosiblesEn(Caracteres, Tamaño, indice+1);
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