#ifndef LISTAARREGLOS_H
#define LISTAARREGLOS_H

#include <climits>
#include <exception>
#include <iostream>

#define REPEAT(n) for (int i = 0; i < (n); ++i)

using namespace std;

class ListaArreglos {
private:
  struct Node {
    int *datos;
    int tamanio;
    Node *next;

    Node(int t, Node *n = nullptr, int *d = nullptr) : tamanio(t), next(n) {
      if (tamanio > 0) {
        datos = new int[tamanio];
        if (d != nullptr) {
          REPEAT(tamanio) { datos[i] = d[i]; }
        } else {
          REPEAT(tamanio) { datos[i] = 0; }
        }
      } else {
        datos = nullptr;
      }
    }
    ~Node() { delete[] datos; }
  };

  Node *head;
  Node *tail;
  int size;

public:
  typedef Node *tPosition;

  ListaArreglos() : size(0) {
    tail = new Node(0);
    head = new Node(0, tail);
    size = 0;
  }

  ListaArreglos(const ListaArreglos &other) : size(0) {
    tail = new Node(0);
    head = new Node(0, tail);
    size = 0;

    tPosition current_other = other.first();
    while (current_other != other.Tail()) {
      PushBack(current_other->tamanio, current_other->datos);
      next(current_other);
    }
  }

  ~ListaArreglos() {
    Node *current = head;
    while (current != nullptr) {
      Node *temp = current->next;
      delete current;
      current = temp;
    }
    tail = nullptr;
    head = nullptr;
    size = 0;
  }

  int Size() { return size; }

  bool IsEmpty() const { return size == 0; }

  tPosition first() const { return (head->next != tail) ? head->next : tail; }

  tPosition last() const {
    if (IsEmpty()) {
      return tail;
    }
    tPosition current = first();
    while (current->next != tail) {
      next(current);
    }
    return current;
  }

  tPosition Tail() const { return tail; }

  void next(tPosition &pValue) const {
    if (pValue != tail) {
      pValue = pValue->next;
    }
  }

  int *&get(tPosition v) { return v->datos; }

  int getTamanio(tPosition v) const { return v->tamanio; }
  // Insert arreglo
  void insert(int valor, tPosition posicion) {
    tPosition current = head;
    while (current->next != posicion) {
      next(current);
    }
    if (current->next != posicion) {
      cerr << "Error: La posicion dada no esta en la lista";
      return;
    }
    current->next = new Node(1, posicion, &valor);
    size++;
  }
  void insert(int *ArrInsertar, tPosition PosicionInsertar, int TamanoArr) {
    if (TamanoArr < 0) {
      throw invalid_argument("No puedes tener un tamaño negativo");
    }
    tPosition current = head;
    while (current->next != PosicionInsertar) {
      next(current);
    }
    if (current->next != PosicionInsertar) {
      cerr << "Error: La posicion dada no esta en la lista";
      return;
    }
    current->next = new Node(TamanoArr, PosicionInsertar, ArrInsertar);
    size++;
  }

  void Delete(tPosition PosicionEliminar) {
    if (PosicionEliminar == nullptr) {
      cerr << "Error: No se puede eliminar una posicion nula";
      return;
    }
    if (PosicionEliminar == tail || PosicionEliminar == head) {
      cerr << "Error: No se puede eliminar un nodo centinela (head/tail)";
      return;
    }
    tPosition current = head;
    while (current->next != PosicionEliminar) {
      next(current);
    }
    if (current->next != PosicionEliminar) {
      cerr << "Error: La posicion dada no esta en la lista";
      return;
    }
    current->next = PosicionEliminar->next;
    delete PosicionEliminar;
    size--;
  }

  void printAll() {
    if (IsEmpty()) {
      cout << "{ [ ] }" << endl;
      return;
    }
    tPosition current = first();
    cout << "{";
    while (current != tail) {
      int *CurrentArray = get(current);
      int CurrentSize = current->tamanio;
      cout << " [";
      REPEAT(CurrentSize) {
        cout << CurrentArray[i];
        if (i < CurrentSize - 1)
          cout << ", ";
      }
      cout << " ]";
      if (current->next != tail)
        cout << ", ";
      next(current);
    }
    cout << " }" << endl;
  }

  void clear() {
    tPosition current = first();
    while (current != tail) {
      tPosition temp = current->next;
      delete current;
      current = temp;
    }
    head->next = tail;
    size = 0;
  }

  void SwapDatas(int &data1, int &data2) {
    int aux = data1;
    data1 = data2;
    data2 = aux;
  }

  void OrderAscendent(tPosition node) {
    if (node == nullptr || node->tamanio <= 1) {
      return;
    }
    int *CurrentArray = get(node);
    int CurrentSize = node->tamanio;
    bool IsOrdered = false;
    while (!IsOrdered) {
      IsOrdered = true;
      REPEAT(CurrentSize - 1) {
        if (CurrentArray[i] > CurrentArray[i + 1]) {
          SwapDatas(CurrentArray[i], CurrentArray[i + 1]);
          IsOrdered = false;
        }
      }
    }
  }

  void OrderAscendentAll() {
    for (tPosition current = first(); current != tail; next(current)) {
      OrderAscendent(current);
    }
  }

  bool IsOrderedList() const {
    if (IsEmpty()) {
      return true;
    }
    for (tPosition current = first(); current->next != tail; next(current)) {
      if (!IsOrderedNode(current))
        return false;
    }
    return true;
  }

  bool IsOrderedNode(tPosition node) const {
    if (node == nullptr || node->tamanio <= 1) {
      return true;
    }
    REPEAT(node->tamanio - 1) {
      if (node->datos[i] > node->datos[i + 1])
        return false;
    }
    return true;
  }

  void PushBack(int ArrSize, int *Arr) { insert(Arr, tail, ArrSize); }

  // --- Métodos Resolutivos de Ejercicios ---

  // Ejercicio 3: Buscar elemento n
  tPosition find(int n) {
    tPosition current = first();
    while (current != tail) {
      int *CurrentArray = get(current);
      int CurrentSize = current->tamanio;
      REPEAT(CurrentSize) {
        if (CurrentArray[i] == n) {
          return current;
        }
      }
      next(current);
    }
    return tail;
  }

  // Ejercicio 3: Eliminar todas las ocurrencias de n en un nodo dado
  void deleteByValue(tPosition node, int n) {
    if (node == nullptr || node == tail || node == head || node->tamanio <= 0) {
      return;
    }
    int *OldArray = get(node);
    int OldSize = node->tamanio;
    int contN = 0;
    REPEAT(OldSize) {
      if (OldArray[i] == n) {
        OldArray[i] = INT_MIN;
        contN++;
      }
    }
    if (contN == 0) {
      return;
    }
    int NewSize = OldSize - contN;
    int *NewArray = new int[NewSize];
    int index = 0;
    REPEAT(OldSize) {
      if (OldArray[i] != INT_MIN) {
        NewArray[index] = OldArray[i];
        index++;
      }
    }
    delete[] OldArray;
    node->datos = NewArray;
    node->tamanio = NewSize;
  }

  // Ejercicio 5: Mezcla ordenada de dos listas de arreglos
  static ListaArreglos mezcla2(const ListaArreglos &n1,
                               const ListaArreglos &n2) {
    if (!n1.IsOrderedList() || !n2.IsOrderedList()) {
      cerr << "No estan ordenadas tus dos listas" << endl;
      return ListaArreglos();
    }
    ListaArreglos NewList;

    tPosition current_n1 = n1.first();
    tPosition current_n2 = n2.first();
    tPosition tail_n1 = n1.Tail();
    tPosition tail_n2 = n2.Tail();

    auto getFirstVal = [](tPosition Nodo) -> int {
      if (Nodo == nullptr || Nodo->tamanio <= 0 || Nodo->datos == nullptr) {
        throw runtime_error("Intento de acceder a un nodo invalido");
      }
      return Nodo->datos[0];
    };

    while (current_n1 != tail_n1 && current_n2 != tail_n2) {
      if (getFirstVal(current_n1) <= getFirstVal(current_n2)) {
        NewList.PushBack(current_n1->tamanio, current_n1->datos);
        n1.next(current_n1);
      } else {
        NewList.PushBack(current_n2->tamanio, current_n2->datos);
        n2.next(current_n2);
      }
    }
    while (current_n1 != tail_n1) {
      NewList.PushBack(current_n1->tamanio, current_n1->datos);
      n1.next(current_n1);
    }
    while (current_n2 != tail_n2) {
      NewList.PushBack(current_n2->tamanio, current_n2->datos);
      n2.next(current_n2);
    }
    return NewList;
  }
};

#endif // LISTAARREGLOS_H
