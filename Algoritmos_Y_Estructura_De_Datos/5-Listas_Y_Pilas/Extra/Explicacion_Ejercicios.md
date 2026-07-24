# Guía Explicativa Completa: Ejercicios de Listas y Pilas

Este documento detalla conceptual y algorítmicamente la resolución de todos los ejercicios de la carpeta [5-Listas_Y_Pilas](file:///c:/Users/AARON/Documents/GitHub/Guia_Ejercicios/Algoritmos_Y_Estructura_De_Datos/5-Listas_Y_Pilas). Todos los ejercicios han sido refactorizados para consumir las estructuras de datos personalizadas de la carpeta [9-Estructuras_Base](file:///c:/Users/AARON/Documents/GitHub/Guia_Ejercicios/Algoritmos_Y_Estructura_De_Datos/9-Estructuras_Base), asegurando consistencia y modularidad absoluta.

---

## Índice de Ejercicios
1. [Ejercicio 3: Eliminación de Ocurrencias en Listas de Arreglos](#ejercicio-3-eliminación-de-ocurrencias-en-listas-de-arreglos)
2. [Ejercicio 5: Mezcla Ordenada de Listas de Arreglos](#ejercicio-5-mezcla-ordenada-de-listas-de-arreglos)
3. [Ejercicio 6: Simulación de Lista Circular de Caracteres](#ejercicio-6-simulación-de-lista-circular-de-caracteres)
4. [Ejercicio 9: Suma de Elementos de una Lista](#ejercicio-9-suma-de-elementos-de-una-lista)
5. [Ejercicio 12: Eliminar Valores Repetidos de una Lista](#ejercicio-12-eliminar-valores-repetidos-de-una-lista)
6. [Ejercicio 15: Inversión de Lista Enlazada (Iterativo y Recursivo)](#ejercicio-15-inversión-de-lista-enlazada-iterativo-y-recursivo)
7. [Ejercicio 17: Inversión de una Pila mediante Recursión](#ejercicio-17-inversión-de-una-pila-mediante-recursión)
8. [Ejercicio 20: Conversión y Evaluación de Notación Polaca](#ejercicio-20-conversión-y-evaluación-de-notación-polaca)
9. [Ejercicio 22: Promedio de los Elementos de una Pila](#ejercicio-22-promedio-de-los-elementos-de-una-pila)

---

## Ejercicio 3: Eliminación de Ocurrencias en Listas de Arreglos
**Archivo**: [03-EliminarN.cpp](file:///c:/Users/AARON/Documents/GitHub/Guia_Ejercicios/Algoritmos_Y_Estructura_De_Datos/5-Listas_Y_Pilas/03-EliminarN.cpp) | Estructura: [ListaArreglos.h](file:///c:/Users/AARON/Documents/GitHub/Guia_Ejercicios/Algoritmos_Y_Estructura_De_Datos/9-Estructuras_Base/ListaArreglos.h)

### Explicación
Cada nodo de esta lista personalizada contiene un **arreglo dinámico de enteros** (`int* datos`) y su tamaño (`int tamanio`). El algoritmo busca y elimina todas las ocurrencias del número $n$ modificando dinámicamente el arreglo de cada nodo.
* La estructura ha sido trasladada a la estructura base [ListaArreglos.h](file:///c:/Users/AARON/Documents/GitHub/Guia_Ejercicios/Algoritmos_Y_Estructura_De_Datos/9-Estructuras_Base/ListaArreglos.h) como la clase `ListaArreglos`.
* El método `deleteByValue(node, n)` cuenta cuántas veces aparece $n$ en el arreglo del nodo actual, crea un nuevo arreglo de tamaño reducido sin las ocurrencias de $n$, libera el antiguo arreglo y reasigna los punteros y el tamaño.

---

## Ejercicio 5: Mezcla Ordenada de Listas de Arreglos
**Archivo**: [05-MezclarListas.cpp](file:///c:/Users/AARON/Documents/GitHub/Guia_Ejercicios/Algoritmos_Y_Estructura_De_Datos/5-Listas_Y_Pilas/05-MezclarListas.cpp) | Estructura: [ListaArreglos.h](file:///c:/Users/AARON/Documents/GitHub/Guia_Ejercicios/Algoritmos_Y_Estructura_De_Datos/9-Estructuras_Base/ListaArreglos.h)

### Explicación
Dadas dos listas de arreglos de enteros previamente ordenados ascendentemente, la función estática `ListaArreglos::mezcla2` produce una tercera lista que contiene todos los arreglos combinados y ordenados.
* Compara el primer elemento del arreglo del nodo de la primera lista con el del nodo de la segunda lista.
* El nodo menor se inserta en la nueva lista mediante copia profunda y avanzamos en su respectiva lista original.
* Al final de una de las listas, se añaden los nodos restantes de la otra lista de manera consecutiva.

---

## Ejercicio 6: Simulación de Lista Circular de Caracteres
**Archivo**: [06-SimularCircular.cpp](file:///c:/Users/AARON/Documents/GitHub/Guia_Ejercicios/Algoritmos_Y_Estructura_De_Datos/5-Listas_Y_Pilas/06-SimularCircular.cpp) | Estructura: [ListaCircular.h](file:///c:/Users/AARON/Documents/GitHub/Guia_Ejercicios/Algoritmos_Y_Estructura_De_Datos/9-Estructuras_Base/ListaCircular.h)

### Explicación
Simula un recorrido circular infinito sobre un conjunto de strings.
* Utiliza la estructura base `ListaCircular`, donde el último nodo físico tiene su puntero `next` apuntando a `head` (el centinela inicial).
* Para imprimir $m$ valores a partir de $i$, calcula la posición inicial usando aritmética modular ($i \pmod{\text{size}}$) para ubicarse.
* Recorre imprimiendo los elementos y saltándose de forma automática el nodo centinela `head` cuando pasa por él.

---

## Ejercicio 9: Suma de Elementos de una Lista
**Archivo**: [09-SumaLista.cpp](file:///c:/Users/AARON/Documents/GitHub/Guia_Ejercicios/Algoritmos_Y_Estructura_De_Datos/5-Listas_Y_Pilas/09-SumaLista.cpp) | Estructura: [ListaSimple.h](file:///c:/Users/AARON/Documents/GitHub/Guia_Ejercicios/Algoritmos_Y_Estructura_De_Datos/9-Estructuras_Base/ListaSimple.h)

### Explicación
Obtiene la suma total de los elementos de una lista lineal de enteros.
* Delega al método `intList::suma()` en la estructura base.
* Recorre secuencialmente todos los nodos desde `head->next` sumando los valores acumulados hasta tocar el centinela final `tail`.

---

## Ejercicio 12: Eliminar Valores Repetidos de una Lista
**Archivo**: [12-EliminarRepetidos.cpp](file:///c:/Users/AARON/Documents/GitHub/Guia_Ejercicios/Algoritmos_Y_Estructura_De_Datos/5-Listas_Y_Pilas/12-EliminarRepetidos.cpp) | Estructura: [ListaSimple.h](file:///c:/Users/AARON/Documents/GitHub/Guia_Ejercicios/Algoritmos_Y_Estructura_De_Datos/9-Estructuras_Base/ListaSimple.h)

### Explicación
Elimina físicamente cualquier ocurrencia duplicada posterior de un valor en la lista.
* Delega a `intList::eliminarRepetidos()`.
* Usa un puntero principal `current` que fija el valor a contrastar, y un puntero secundario `runner` que avanza por la sublista restante eliminando con `Delete()` los duplicados.
* El avance del puntero secundario se realiza *antes* de borrar físicamente el nodo para no perder la referencia.

---

## Ejercicio 15: Inversión de Lista Enlazada (Iterativo y Recursivo)
**Archivo**: [15-InvertirLista.cpp](file:///c:/Users/AARON/Documents/GitHub/Guia_Ejercicios/Algoritmos_Y_Estructura_De_Datos/5-Listas_Y_Pilas/15-InvertirLista.cpp) | Estructura: [ListaSimple.h](file:///c:/Users/AARON/Documents/GitHub/Guia_Ejercicios/Algoritmos_Y_Estructura_De_Datos/9-Estructuras_Base/ListaSimple.h)

### Explicación
Invierte el enlace físico de los nodos de datos (el puntero `next`) manteniendo intactos los valores internos y sin crear nuevos nodos (sin `new` / `Delete`).
* **Iterativo**: Utiliza tres punteros (`prev = tail`, `curr = head->next`, `next_node`) para ir invirtiendo paso a paso cada puntero. Al final reconecta `head->next` con el último nodo original.
* **Recursivo**: Usa recursividad para descender hasta el final de la lista de datos. Al retornar de la recursión, realiza las asignaciones: `curr->next->next = curr` y `curr->next = tail`.

---

## Ejercicio 17: Inversión de una Pila mediante Recursión
**Archivo**: [17-InvertirPila.cpp](file:///c:/Users/AARON/Documents/GitHub/Guia_Ejercicios/Algoritmos_Y_Estructura_De_Datos/5-Listas_Y_Pilas/17-InvertirPila.cpp) | Estructura: [PilaSimple.h](file:///c:/Users/AARON/Documents/GitHub/Guia_Ejercicios/Algoritmos_Y_Estructura_De_Datos/9-Estructuras_Base/PilaSimple.h)

### Explicación
Invierte el orden de los elementos de una pila usando exclusivamente sus primitivas (`Push()`, `Pop()`, `IsEmpty()`) sin estructuras de almacenamiento adicionales.
* La pila de llamadas de recursión almacena temporalmente los elementos.
* `invertir()` desapila el elemento del tope (`temp = Pop()`), se llama a sí misma recursivamente para invertir el resto de la pila y, finalmente, lo inserta en la base mediante `insertAtBottom(temp)`.
* `insertAtBottom()` es otra función recursiva que desapila la pila hasta que está vacía, realiza un `Push(item)` en el fondo y, al retornar, vuelve a apilar los elementos previamente extraídos.

---

## Ejercicio 20: Conversión y Evaluación de Notación Polaca
**Archivo**: [20-Notacionpolaca.cpp](file:///c:/Users/AARON/Documents/GitHub/Guia_Ejercicios/Algoritmos_Y_Estructura_De_Datos/5-Listas_Y_Pilas/20-Notacionpolaca.cpp) | Estructuras: [ListaTemplate.h](file:///c:/Users/AARON/Documents/GitHub/Guia_Ejercicios/Algoritmos_Y_Estructura_De_Datos/9-Estructuras_Base/ListaTemplate.h) y [Pila.h](file:///c:/Users/AARON/Documents/GitHub/Guia_Ejercicios/Algoritmos_Y_Estructura_De_Datos/9-Estructuras_Base/Pila.h)

### Explicación
Convierte expresiones infijas (normales con paréntesis) a notación prefija (polaca) y las evalúa.
* Consume la pila templada `Stack<string>` y la lista templada `List<string>`.
* **Conversión**: Invierte la expresión infija, realiza la conversión a postfija clásica mediante Shunting-Yard (respetando la asociatividad derecha y operadores de precedencia) e invierte el resultado final.
* **Evaluación**: Recorre la expresión polaca de derecha a izquierda (usando una pila auxiliar). Si encuentra un operando, lo introduce a la pila de operandos; si encuentra un operador binario, desapila dos valores de la pila de operandos, calcula la operación e introduce el resultado en la pila de operandos. El resultado final quedará como único valor en la pila.

---

## Ejercicio 22: Promedio de los Elementos de una Pila
**Archivo**: [22-PromedioPila.cpp](file:///c:/Users/AARON/Documents/GitHub/Guia_Ejercicios/Algoritmos_Y_Estructura_De_Datos/5-Listas_Y_Pilas/22-PromedioPila.cpp) | Estructura: [PilaSimple.h](file:///c:/Users/AARON/Documents/GitHub/Guia_Ejercicios/Algoritmos_Y_Estructura_De_Datos/9-Estructuras_Base/PilaSimple.h)

### Explicación
Calcula el valor promedio (aritmético) de los elementos de una pila recorriéndola una única vez.
* Utiliza `PilaSimple` para enteros.
* Obtiene la cantidad de elementos con `Size()` y recorre la pila acumulando la suma de los valores desapilados (`Pop()`) uno por uno hasta vaciarla.
* Retorna el cálculo en punto flotante: `(float)suma / tamaño`.
