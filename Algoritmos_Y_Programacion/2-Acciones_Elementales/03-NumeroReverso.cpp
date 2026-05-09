#include<iostream>
using namespace std;
/*Escriba un algoritmo que lea un número de cuatro dígitos y muestre en
pantalla el número escrito en reverso. Por ejemplo, si el número es 4678, la
salida debería ser 8764.*/
int main(){
    
    int d1,d2,d3,d4; //Declaramos nuestra variables de tipo entero
    
    int x; //Nuestro numero a ingresar
    
    cout<< "Introduzca un N de 4 digitos "<< endl;
    
    cin>>x; // Aqui ya tenemos el numero 1234

    d4 = x % 10; // 1234 % 10 -> Obtenemos el resto 4
    x /= 10; // Equivalente a x = x / 10; 
    d3 = x % 10; // 123 % 10 -> Obtenemos el resto 3 
    x /= 10;
    d2 = x % 10; // 12 % 10 -> 2
    x /= 10;
    d1 = x; // 1 % 10 -> 1 
    /*
    Otra forma de hacer esto un poco mas directo seria:
    d4 = x % 10;
    d3 = (x / 10) % 10;
    d2 = (x / 100) % 10
    d1 = (x / 1000) % 10
    El sentido de esto es que dividimos en potencias de 10, donde por decirse que 
    con el / por cada 0 se elimina un numero de la derecha (O si trabajas con flotantes se desplaza) 1234  / 100 -> 12.34
    Y con el % por cada 0 se obtiene cada numero de la derecha 1'234' % 1'000' -> 234
    */
    // Tenemos 1, 2, 3, 4 Queremos 4321
    int NumeroResultante = (d4 * 1000) ; // NR = 4000
    NumeroResultante += d3 * 100; // NR = 4300
    NumeroResultante += d2 * 10; // NR = 4320
    NumeroResultante += d1 * 1; // NR = 4321 El * 1 se puede quitar perfectamente
    //Factorizando el codigo se tiene algo en una sola linea como
    // int  NumeroResultante = (d4 * 1000) + (d3 * 100) + (d2 * 10) + d1

    cout<<" Tu numero volteado es: "<<NumeroResultante<< endl; // Opcion 1
    cout<< d4 << d3 << d2 << d1 << endl; // Opcion 2
    

    return 0;
}
