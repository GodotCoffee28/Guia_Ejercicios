#include<iostream>
using namespace std;
/*8. Un número de 4 cifras es felíz si los dos primeros dígitos son mayores que
los dos últimos dígitos. Por ejemplo 5612 es felíz porque 56 es mayor que
12. Un número de 4 cifras es creciente si cada dígito es mayor al anterior.
Por ejemplo 1569 es creciente porque 9 > 6 > 5 > 1. Todo número que es
felíz y creciente se dice que es un número muy felíz. Todo número que no es
felíz ni creciente se dice que es infelíz. Haga un algoritmo que tome como
entrada un número de 4 dígitos e imprima el tipo de número encontrado,
según la clasficicación descrita.*/

int main(){

int V1, V2, V3, V4;
int P1, P2;
int Num;

cin>> Num; //5612
int temp = Num; // Como vamos a modificar temp y lo necesitaremos luego, la guardamos
V4 = temp % 10; // 5612 % 10 -> Obtenemos el resto 2
temp /= 10; // Equivalente a temp = temp / 10; 
V3 = temp % 10; // 561 % 10 -> Obtenemos el resto 1 
temp /= 10;
V2 = temp % 10; // 56 % 10 -> 6
temp /= 10;
V1 = temp; // 5 % 10 -> 5 
// temp = 5; Pero tenemos Num = 5612
//P1 = 51 y P2 = 
P2 = Num % 100; // 5612 % 100 -> 12
P1 = Num / 100; // 5612 / 100 -> 56

// PRIMERA CONDICION, que el numero sea Feliz
if( P1 > P2 ){ 
    cout<< " Es feliz :D"<<endl;
} 
//SEGUNDA CONDICION, que el numero sea creciente
if(V1 > V2 && V2 > V3 && V3 > V4){ // No puedes hacer directamente V1> V2 > V3
    cout<< " Es creciente >>>:D"<<endl;
}
// TERCERA CONDICION, que el numero sea feliz y creciente
if((P1 > P2 ) && (V1 > V2 && V2 > V3 && V3 > V4)){
    cout<< "ES MUY FELIZ >>>:DDD"<<endl;
} 

//ULTIMA CONDICION, que no sea feliz ni creciente
if(!(P1 > P2 ) && !(V1 > V2 && V2 > V3 && V3 > V4)){
    cout<< "es infeliz D:"<<endl;
}

    return 0;
}
