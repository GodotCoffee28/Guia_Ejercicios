/*11. Dadas las ecuaciones de dos rectas no paralelas y = m1x+b1 y y = m2x+b2,
escribir un algoritmo que calcule su punto de intersección.*/

#include<iostream>
using namespace std;
//Esto es mas matematico que de programacion
//Tenemos que igualar las rectas para ver que valores en el eje x hacen intercecion en ambas rectas
//m1x+b1 = m2x+b2 
//Despejar x
//m1x+b1 = m2x+b2  -> m1x-m2x = b2 - b1 -> x(m1-m2) = b2 - b1 
//x = b2 - b1 / m1 - m2 
//Ahora, nos estan pidiendo el punto, falta el eje y de ese x
// y = m1x+b1 usamos esto y el x será el que calculemos
//Solo representar eso con acciones elementales

int main(){
    float b1,b2,m1,m2;
    cin>>b1>>m1>>b2>>m2;

    float x = (b2 - b1) / (m1 - m2);
    float y = m1*x+b1; //O usar el del 2

    cout<<"("<<x<<","<<y<<")";
    return 0;
}