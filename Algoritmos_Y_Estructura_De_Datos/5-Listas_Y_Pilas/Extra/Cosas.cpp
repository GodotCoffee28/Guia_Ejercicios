
#include<iostream>
#include<exception>
#include<string>

#include "../../9-Estructuras_Base/Dipolo.h"


using namespace std;
template<typename T>
void OpcionesDeque(Deque<T>& Dipolo);
void menu(){
cout<<"BIENVENIDO A 'COSAS', DONDE TENEMOS UNA VARIEDAD DE ESTRUCTURAS DE DATOS PARA USTED\nPor el momento, tenemos solo dipolos. \n¿Que tipo de dato sera su Dipolo?"<<endl;
cout<<"1-int\n2-float\n3-char\n4-string\n5-bool"<<endl;
int TipoDeDato; 
do{
cin>>TipoDeDato;

Deque<int> Dequeint;
Deque<float> Dequefloat;
Deque<char> Dequechar;
Deque<string> Dequestring;
Deque<bool> Dequebool;

switch(TipoDeDato){
    case 1:OpcionesDeque(Dequeint); break;
    case 2:OpcionesDeque(Dequefloat); break;
    case 3:OpcionesDeque(Dequechar); break;
    case 4:OpcionesDeque(Dequestring); break;
    case 5:OpcionesDeque(Dequebool); break;
    default: cout<<"INGRESE UNO DE LOS DATOS INDICADOS"<<endl;
}
}while(TipoDeDato>5 || TipoDeDato<1);
}
template<typename T>
void OpcionesDeque(Deque<T>& Dipolo){
    cout<<"GENIAL, ESTAS SON LAS OPCIONES QUE TENEMOS PARA SU DIPOLO:"<<endl;
    bool running = true;
    string Opciones[] = {
        "1-Poner elemento hasta el frente",
        "2-Poner elemento hasta atrás",
        "3-Eliminar elemento en el frente",
        "4-Eliminar elemento hasta atrás",
        "5-Ver elemento del frente",
        "6-Ver elemento hasta atrás",
        "7-¿La lista esta vacia?",
        "8-Tamaño de la lista",
        "9-Limpiar toda la lista",
        "10-Mostrar toda la lista", 
        "11-Salir"
    };
    while(running){ 
    for(int i=0; i<sizeof(Opciones)/sizeof(Opciones[0]); i++){
        cout<<Opciones[i]<<endl;
    }
    int OpcionARealizar;
    
    while (!(cin >> OpcionARealizar)) {
            cout << "Entrada inválida. Por favor, ingrese un número: ";
            cin.clear(); // Limpiar el estado de error
            cin.ignore();

        }
try { // Usamos un bloque try-catch para manejar las excepciones de la Deque
            switch(OpcionARealizar) {
                case 1: { // 1-Poner elemento hasta el frente
                    T value;
                    cout << "Ingrese el valor a añadir al frente: ";
                    cin >> value;
                    Dipolo.PushFront(value);
                    cout << "Elemento añadido. Dipolo actual: " << Dipolo << endl;
                    break;
                }
                case 2: { // 2-Poner elemento hasta atrás
                    T value;
                    cout << "Ingrese el valor a añadir al final: ";
                    cin >> value;
                    Dipolo.PushBack(value);
                    cout << "Elemento añadido. Dipolo actual: " << Dipolo << endl;
                    break;
                }
                case 3: { // 3-Eliminar elemento en el frente
                    Dipolo.PopFront();
                    cout << "Elemento del frente eliminado. Dipolo actual: " << Dipolo << endl;
                    break;
                }
                case 4: { // 4-Eliminar elemento hasta atrás
                    Dipolo.PopBack();
                    cout << "Elemento de atrás eliminado. Dipolo actual: " << Dipolo << endl;
                    break;
                }
                case 5: { // 5-Ver elemento del frente
                    cout << "Elemento del frente: " << Dipolo.Front() << endl;
                    break;
                }
                case 6: { // 6-Ver elemento hasta atrás
                    cout << "Elemento hasta atrás: " << Dipolo.Back() << endl;
                    break;
                }
                case 7: { // 7-¿La lista esta vacia?
                    if (Dipolo.IsEmpty()) {
                        cout << "La lista está vacía." << endl;
                    } else {
                        cout << "La lista NO está vacía." << endl;
                    }
                    break;
                }
                case 8: { // 8-Tamaño de la lista
                    cout << "Tamaño de la lista: " << Dipolo.Size() << endl;
                    break;
                }
                case 9: { // 9-Limpiar toda la lista
                    Dipolo.Clear();
                    cout << "Lista limpiada. Dipolo actual: " << Dipolo << endl;
                    break;
                }
                case 10: { // 10-Mostrar toda la lista
                    cout << "Contenido del Dipolo: " << Dipolo << endl;
                    break;
                }
                case 11: { // 11-Salir
                    cout << "Saliendo del menú de opciones del Dipolo. ¡Hasta luego!" << endl;
                    running = false; // Cambia la bandera para salir del bucle
                    break;
                }
                default: {
                    cout << "Opción no válida. Por favor, intente de nuevo." << endl;
                    break;
                }
            }
        } catch (const out_of_range& e) {
            cerr << e.what() << endl;
        } catch (const exception& e) { // Captura otras posibles excepciones
            cerr << "Un error inesperado ocurrió: " << e.what() << endl;
        }
        cout << endl; // Salto de línea para mejor legibilidad entre opciones
        }
   }


int main(){
 menu();
    return 0;
}