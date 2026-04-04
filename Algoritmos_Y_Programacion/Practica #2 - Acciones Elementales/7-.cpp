/*Escriba un algoritmo que dados la distancia recorrida por un objeto y el
tiempo que tomó el objeto en recorrer esa distancia, calcule su velocidad*/

#include<iostream>
using namespace std;

int main(){

    int min = 0;
    int distancia = 0;
    float vel = 0; 
    
    cin>>min>>distancia;

    vel = distancia / min;

    cout<<vel<<endl;


    return 0;
}