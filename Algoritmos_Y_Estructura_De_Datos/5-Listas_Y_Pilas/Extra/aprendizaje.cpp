#include <iostream>
#include <algorithm> // Para std::copy

template<typename T> // Eliminamos N de la plantilla
class Array {
private:
    int tamanio;
    T* MyArray;

public:
    // Constructor por defecto
    // Crea un arreglo vacío o de tamaño 0
    Array() : tamanio(0), MyArray(nullptr) {}

    // Constructor que toma un tamaño inicial
    explicit Array(int large) : tamanio(large) {
        if (tamanio < 0) {
            tamanio = 0; // Asegura que el tamaño no sea negativo
        }
        MyArray = new T[tamanio](); // Inicializa elementos a 0/null
    }

    // --- Regla de los Tres/Cinco ---

    // 1. Constructor de Copia
    Array(const Array& other) : tamanio(other.tamanio) {
        MyArray = new T[tamanio];
        // Copia los elementos del arreglo 'other' al nuevo arreglo
        std::copy(other.MyArray, other.MyArray + tamanio, MyArray);
    }

    // 2. Operador de Asignación de Copia
    Array& operator=(const Array& other) {
        if (this != &other) { // Evita auto-asignación (a = a;)
            delete[] MyArray; // Libera la memoria antigua

            tamanio = other.tamanio;
            MyArray = new T[tamanio];
            std::copy(other.MyArray, other.MyArray + tamanio, MyArray);
        }
        return *this; // Devuelve una referencia al objeto actual
    }

    // 3. Destructor
    ~Array() {
        delete[] MyArray; // Libera la memoria asignada
        MyArray = nullptr; // Buena práctica para evitar "dangling pointers"
        tamanio = 0;
    }

    // --- Métodos de la clase ---

    int GetTamanio() const { // Agregamos 'const' porque no modifica el objeto
        return tamanio;
    }

    // Operador de inserción (cout <<)
    friend std::ostream& operator<<(std::ostream& os, const Array<T>& Arr) {
        os << "{ ";
        for (int i = 0; i < Arr.tamanio; i++) { // Usar Arr.tamanio
            os << Arr.MyArray[i];
            if (i != Arr.tamanio - 1) os << ", ";
        }
        os << " }\n";
        return os;
    }

    // Operador de extracción (cin >>)
    friend std::istream& operator>>(std::istream& is, Array<T>& Arr) {
        std::cout << "Ingresa " << Arr.tamanio << " elementos:\n";
        for (int i = 0; i < Arr.tamanio; i++) {
            is >> Arr.MyArray[i];
        }
        return is;
    }

    // Operador para añadir un elemento (ahora como un método que modifica el objeto)
    // El operador '+' usualmente no modifica el objeto original, sino que devuelve uno nuevo.
    // Para simplificar, lo haremos que modifique el objeto actual, pero es bueno saber la convención.
    void addElement(T newData) { // Cambiado a un método void, o podrías devolver un nuevo Array.
        // 1. Crear un nuevo arreglo más grande
        int nuevoTamanio = tamanio + 1;
        T* newArray = new T[nuevoTamanio]();

        // 2. Copiar los elementos antiguos al nuevo arreglo
        if (MyArray) { // Asegúrate de que MyArray no sea nullptr si el Array estaba vacío
            std::copy(MyArray, MyArray + tamanio, newArray);
        }

        // 3. Añadir el nuevo dato al final
        newArray[nuevoTamanio - 1] = newData;

        // 4. Liberar la memoria del arreglo antiguo
        delete[] MyArray;

        // 5. Actualizar los miembros del objeto actual
        MyArray = newArray;
        tamanio = nuevoTamanio;
    }
    
    // Si realmente quieres un operador+ que devuelva un *nuevo* Array, sería así:
    /*
    Array operator+(T newData) const { // 'const' porque no modifica el objeto actual
        Array result(tamanio + 1); // Crea un nuevo Array con el nuevo tamaño
        // Copia los elementos del objeto actual a 'result'
        std::copy(MyArray, MyArray + tamanio, result.MyArray);
        // Añade el nuevo dato al final de 'result'
        result.MyArray[result.tamanio - 1] = newData;
        return result; // Devuelve el nuevo Array
    }
    */
    
    // Para acceso a elementos (como [] en un arreglo normal)
    T& operator[](int index) {
        if (index < 0 || index >= tamanio) {
            // Manejo de error: podrías lanzar una excepción
            std::cerr << "Error: Índice fuera de rango.\n";
            exit(EXIT_FAILURE); // Salir del programa por simplicidad, en real se lanza excepción
        }
        return MyArray[index];
    }

    const T& operator[](int index) const { // Versión const para objetos const Array
        if (index < 0 || index >= tamanio) {
            std::cerr << "Error: Índice fuera de rango (const).\n";
            exit(EXIT_FAILURE);
        }
        return MyArray[index];
    }
};

int main() {
    // Crear un Array con un tamaño inicial de 5
    Array<int> Enteros(5); 
    
    std::cout << "Ingresa 5 numeros enteros para tu arreglo:\n";
    std::cin >> Enteros; // Usa el operador >> para llenar el arreglo
    std::cout << "Tu arreglo inicial es: " << Enteros;

    // Usando el nuevo método addElement para añadir un número
    Enteros.addElement(100);
    std::cout << "Despues de añadir 100: " << Enteros;

    Enteros.addElement(200);
    std::cout << "Despues de añadir 200: " << Enteros;

    // Acceder a un elemento
    std::cout << "El primer elemento es: " << Enteros[0] << std::endl;
    Enteros[0] = 500;
    std::cout << "Arreglo despues de modificar el primer elemento: " << Enteros;

    // Demostrando el constructor y operador de copia
    Array<int> OtroArray = Enteros; // Usa el constructor de copia
    std::cout << "OtroArray (copia de Enteros): " << OtroArray;

    Array<int> TercerArray(2);
    TercerArray = Enteros; // Usa el operador de asignación de copia
    std::cout << "TercerArray (asignacion de Enteros): " << TercerArray;

    return 0;
}