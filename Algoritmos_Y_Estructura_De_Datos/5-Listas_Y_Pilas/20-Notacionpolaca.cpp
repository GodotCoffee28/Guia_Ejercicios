/*La notación polaca debe su nombre al famoso matemático polaco Jan Lukasiewicz, 
y se basa en que el símbolo operador se coloca delante de sus operandos. 
Asumiendo que todos los operadores a trabajar son binarios, se desea que:
• Transforme una expresión en forma normal (operando operador operando) almacenada en una lista,
la almacene en una pila en notación polaca. Asuma que la expresión de entrada puede tener paréntesis.

• Elabore un algoritmo que permita evaluar una expresión en notación polaca almacenada en una pila.
Ejemplo de notaciones polacas:
+ A B, que es equivalente a A + B;
+ a / b c, que es equivalente a a + b/c.*/
#include <iostream>
#include <list>
#include <string>
using namespace std;

int main(){
    list<string> l;
    list<string>::iterator it;
    // a + b
    
    l.push_back("1");
    it = l.begin();
    ++it;
    l.push_back("+");
    l.push_back("2");




    for(it= l.begin(); it != l.end(); ++it)
    cout<< " " << *it;
}