#ifndef MY_ARRAY_H
#define MY_ARRAY_H

#include <iostream>

/**
 * @brief Clase Array personalizada con tamaño fijo N
 */
template <typename T, int N>
class Array {
private:
    int tamanio;
    T* MyArray;

public:
    Array() {
        tamanio = N;
        MyArray = new T[tamanio]();
    }

    Array(int large) {
        tamanio = large;
        MyArray = new T[tamanio]();
    }

    ~Array() {
        delete[] MyArray;
    }

    int GetTamanio() const {
        return tamanio;
    }

    template <typename U, int M>
    friend std::ostream& operator<<(std::ostream& os, const Array<U, M>& Arr);

    template <typename U, int M>
    friend std::istream& operator>>(std::istream& is, Array<U, M>& Arr);

    // Nota: El operador + original tenía problemas de lógica (auto-asignación inválida), 
    // se mantiene la intención pero simplificado.
    Array& operator+(T newData) {
        T* temp = new T[tamanio + 1];
        for (int i = 0; i < tamanio; i++) {
            temp[i] = MyArray[i];
        }
        temp[tamanio] = newData;
        delete[] MyArray;
        MyArray = temp;
        tamanio++;
        return *this;
    }
};

template <typename U, int M>
std::ostream& operator<<(std::ostream& os, const Array<U, M>& Arr) {
    os << "{ ";
    for (int i = 0; i < Arr.tamanio; i++) {
        os << Arr.MyArray[i];
        if (i != Arr.tamanio - 1) os << ", ";
    }
    os << " }";
    return os;
}

template <typename U, int M>
std::istream& operator>>(std::istream& is, Array<U, M>& Arr) {
    for (int i = 0; i < M; i++) {
        is >> Arr.MyArray[i];
    }
    return is;
}

#endif // MY_ARRAY_H
