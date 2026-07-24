#include <iostream>
#include <string>
#include <cctype>
#include "../9-Estructuras_Base/Pila.h"
#include "../9-Estructuras_Base/ListaTemplate.h"

using namespace std;

/*
 * Ejercicio 20: 
 * • Transforme una expresión en forma normal (operando operador operando) almacenada en una lista,
 *   la almacene en una pila en notación polaca (prefija). Asuma que la expresión de entrada puede tener paréntesis.
 * • Elabore un algoritmo que permita evaluar una expresión en notación polaca almacenada en una pila.
 */

// Función auxiliar para determinar la precedencia de los operadores
int precedencia(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Función auxiliar para verificar si un string es operador
bool esOperador(const string& s) {
    return s == "+" || s == "-" || s == "*" || s == "/";
}

// Convierte una expresión infija (en List<string>) a prefija (en Stack<string>)
Stack<string> infijaAPrefija(List<string>& infija) {
    // 1. Invertir la expresión infija
    List<string> invertida;
    List<string>::tPosition current = infija.first();
    while (current != infija.last()) {
        string elemento = infija.get(current);
        if (elemento == "(") elemento = ")";
        else if (elemento == ")") elemento = "(";
        
        // Insertamos al inicio para invertir
        invertida.insert(elemento, invertida.first());
        infija.next(current);
    }

    // 2. Obtener notación postfija de la expresión invertida (Shunting-yard)
    List<string> postfijaInvertida;
    Stack<string> operadores;

    current = invertida.first();
    while (current != invertida.last()) {
        string token = invertida.get(current);

        if (isdigit(token[0]) || isalpha(token[0])) {
            // Operando: va directo a la salida
            postfijaInvertida.insert(token, postfijaInvertida.last());
        } else if (token == "(") {
            operadores.Push(token);
        } else if (token == ")") {
            while (!operadores.IsEmpty() && operadores.Top() != "(") {
                postfijaInvertida.insert(operadores.Pop(), postfijaInvertida.last());
            }
            if (!operadores.IsEmpty()) operadores.Pop(); // Sacar '('
        } else if (esOperador(token)) {
            while (!operadores.IsEmpty() && 
                   precedencia(operadores.Top()[0]) > precedencia(token[0])) {
                postfijaInvertida.insert(operadores.Pop(), postfijaInvertida.last());
            }
            operadores.Push(token);
        }
        invertida.next(current);
    }

    while (!operadores.IsEmpty()) {
        postfijaInvertida.insert(operadores.Pop(), postfijaInvertida.last());
    }

    // 3. Invertir el resultado postfijo para obtener la notación prefija final
    // y guardarla en la pila de salida
    Stack<string> resultadoPrefijo;
    current = postfijaInvertida.first();
    while (current != postfijaInvertida.last()) {
        resultadoPrefijo.Push(postfijaInvertida.get(current));
        postfijaInvertida.next(current);
    }

    // El tope de la pila ahora tiene el operador más a la izquierda de la expresión prefija
    return resultadoPrefijo;
}

// Evalúa una expresión prefija almacenada en una pila (donde el tope es el primer elemento)
int evaluarPrefija(Stack<string>& prefija) {
    // Para evaluar de derecha a izquierda, pasamos los elementos a una pila auxiliar
    Stack<string> aux;
    while (!prefija.IsEmpty()) {
        aux.Push(prefija.Pop());
    }

    Stack<int> operandos;
    while (!aux.IsEmpty()) {
        string token = aux.Pop();
        if (isdigit(token[0])) {
            operandos.Push(stoi(token));
        } else if (esOperador(token)) {
            if (operandos.Size() < 2) {
                throw runtime_error("Error: Expresion polaca invalida");
            }
            int op1 = operandos.Pop();
            int op2 = operandos.Pop();
            int res = 0;
            if (token == "+") res = op1 + op2;
            else if (token == "-") res = op1 - op2;
            else if (token == "*") res = op1 * op2;
            else if (token == "/") {
                if (op2 == 0) throw runtime_error("Error: Division por cero");
                res = op1 / op2;
            }
            operandos.Push(res);
        }
    }

    if (operandos.Size() != 1) {
        throw runtime_error("Error: Expresion polaca invalida al final");
    }
    return operandos.Pop();
}

void imprimirLista(List<string>& lista) {
    List<string>::tPosition current = lista.first();
    while (current != lista.last()) {
        cout << lista.get(current) << " ";
        lista.next(current);
    }
    cout << endl;
}

void imprimirPila(Stack<string> pila) {
    while (!pila.IsEmpty()) {
        cout << pila.Pop() << " ";
    }
    cout << endl;
}

int main() {
    cout << "=== EJERCICIO 20: NOTACION POLACA ===" << endl << endl;

    // Crear la expresión infija en una List: ( 5 + 3 ) * 2
    List<string> infija;
    List<string>::tPosition pos = infija.first();
    infija.insert("(", pos);
    infija.insert("5", pos);
    infija.insert("+", pos);
    infija.insert("3", pos);
    infija.insert(")", pos);
    infija.insert("*", pos);
    infija.insert("2", pos);

    cout << "Expresion Infija Original: ";
    imprimirLista(infija);

    // Transformar a prefija
    Stack<string> prefija = infijaAPrefija(infija);
    cout << "Expresion Prefija (Polaca) en Pila (Leida de Tope a Base): ";
    imprimirPila(prefija);

    // Volver a generar para evaluar (ya que imprimirPila la vació)
    prefija = infijaAPrefija(infija);
    int resultado = evaluarPrefija(prefija);
    cout << "Resultado de la Evaluacion: " << resultado << " (Esperado: 16)" << endl;
    cout << "---------------------------------------------" << endl;

    // Otra prueba: 10 + 20 / 5  => + 10 / 20 5 = 14
    List<string> infija2;
    pos = infija2.first();
    infija2.insert("10", pos);
    infija2.insert("+", pos);
    infija2.insert("20", pos);
    infija2.insert("/", pos);
    infija2.insert("5", pos);

    cout << "Expresion Infija Original: ";
    imprimirLista(infija2);

    prefija = infijaAPrefija(infija2);
    cout << "Expresion Prefija (Polaca) en Pila: ";
    imprimirPila(prefija);

    prefija = infijaAPrefija(infija2);
    resultado = evaluarPrefija(prefija);
    cout << "Resultado de la Evaluacion: " << resultado << " (Esperado: 14)" << endl;
    cout << "---------------------------------------------" << endl;

    return 0;
}