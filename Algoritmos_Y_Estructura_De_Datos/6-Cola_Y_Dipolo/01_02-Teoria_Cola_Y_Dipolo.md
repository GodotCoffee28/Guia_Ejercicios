# Teoría de Colas y Dipolos - Ejercicios Conceptuales (01-02)

Conceptos básicos sobre estructuras de acceso restringido.

---

## 1. Diferencia entre Cola, Pila y Dipolo

| Estructura | Disciplina | Descripción |
| :--- | :--- | :--- |
| **Pila (Stack)** | **LIFO** (Last In, First Out) | El último en entrar es el primero en salir. Como una pila de platos. |
| **Cola (Queue)** | **FIFO** (First In, First Out) | El primero en llegar es el primero en ser atendido. Como una fila en el banco. |
| **Dipolo (Deque)** | **Mixta** | Permite insertar y extraer elementos por **ambos extremos** (frente y final). |

**¿Es lo mismo que una lista?** No. Una lista es una estructura de **acceso general**, donde puedes insertar o borrar en cualquier posición. Las pilas, colas y dipolos son **estructuras de acceso restringido**, diseñadas para cumplir una disciplina específica de flujo de datos.

---

## 2. Usos de las Colas en Aplicaciones Realistas

Las colas son fundamentales en computación para gestionar recursos compartidos:

1. **Sistemas Operativos:** Gestión de procesos (CPU Scheduling). Los procesos esperan en una cola para usar el procesador.
2. **Impresoras:** El spooler de impresión organiza los documentos en el orden en que fueron enviados.
3. **Redes:** Los routers utilizan colas para almacenar paquetes de datos que llegan más rápido de lo que pueden ser procesados o transmitidos.
4. **Servidores Web:** Para manejar picos de tráfico, las peticiones de los usuarios se encolan para ser procesadas por los hilos del servidor.
