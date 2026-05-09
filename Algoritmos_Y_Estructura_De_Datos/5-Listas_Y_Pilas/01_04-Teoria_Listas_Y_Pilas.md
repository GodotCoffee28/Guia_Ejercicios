# Teoría de Listas y Pilas - Ejercicios Conceptuales (01-04)

Resumen de conceptos sobre gestión de memoria y estructuras lineales.

---

## 1. ¿Son necesarios los apuntadores para implementar listas?

**No.** Aunque es lo más común en C++, no es estrictamente necesario.

* **Alternativa:** Se pueden implementar listas utilizando **Arreglos de Registros**. En este esquema, el "apuntador" es simplemente un índice (entero) que indica la posición del siguiente elemento en el arreglo. A esto se le llama "Lista con Arreglo" o "Cursores".

---

## 2. Listas con Apuntadores vs. Arreglos

| Estructura | Ventajas | Desventajas |
| :--- | :--- | :--- |
| **Arreglos** | Acceso aleatorio rápido (O(1)). Menor uso de memoria (no hay punteros). | Tamaño fijo. Inserción/Borrado costoso (hay que desplazar elementos). |
| **Listas (Punteros)** | Tamaño dinámico (crecen bajo demanda). Inserción/Borrado eficiente (solo cambian enlaces). | Acceso secuencial lento (O(n)). Mayor uso de memoria por los punteros. |

---

## 3. Concepto: Eliminación en Listas con Arreglos

Para eliminar todos los números `n` en una lista implementada sobre un arreglo:

* Se recorre el arreglo.
* Si se encuentra el valor `n`, se marca la posición como "vacía" (usualmente moviéndola a una pila de nodos disponibles o simplemente desplazando los elementos posteriores si es un arreglo contiguo).
* Es importante mantener la integridad de los índices que conectan la lista.

---

## 4. ¿Son las Listas Estructuras Homogéneas?

**En C++ estándar: Sí.** Por definición de tipos, todos los nodos deben ser del mismo tipo definido en el `struct`.

**Sin embargo...** Es posible tener listas heterogéneas (elementos de distinto tipo/estructura) mediante:

1. **Herencia y Polimorfismo:** Una lista de punteros a una Clase Base que apunta a distintas Clases Hijas.
2. **Punteros Genéricos:** Usando `void*` y casteo de tipos (aunque es menos seguro).
3. **Uniones:** Un nodo que puede contener diferentes tipos de datos.

**Justificación:** El uso de polimorfismo permite que el código trate a todos los nodos como el tipo base, pero cada uno ejecute su propio comportamiento, permitiendo listas de "Formas" que contienen círculos, cuadrados, etc.
