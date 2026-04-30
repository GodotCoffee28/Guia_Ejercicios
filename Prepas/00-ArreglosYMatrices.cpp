#include<iostream>
#include<string>
using namespace std;

/*
Arreglos  en C++

    Concepto: Estructura de un tipo de dato ya sea elemental o heterogeneo (Class o struct)
    donde son bloques de memoria ininterrumpidas siempre del mismo tamaño y del mismo dato


Ejemplo de un arreglo

    int Array[6] = {0};
    [0][0][0][0][0][0] Cada corchete "[]" es un espacio de memoria que contiene 0 (porque lo inicializamos asi)
    Si no se inicializa o se le asigna algun valor, lo que habrá en cada espacio de memoria será lo que ya había
    en ese espacio de memoria en la RAM antes de usarla como arreglo (datos basura)

Hablemos de la memoria con los arreglos: ¿Por qué memoria contigua?

    Usando el mismo int Array[6]; Usando sizeof(int) (que tiene el tamaño en bytes de un tipo de dato)
    Tenemos que el tamaño en bytes de un entero es de 4 bytes, el sistema tiene que reservar exactamente 4*6 = 24 bytes
    consecutivos en la RAM, no hay espacios vacíos u otra cosa entre las posiciones de un arreglo.

    4 bytes cada posición del arreglo, en memoria podría iniciarse la primera posicion del arreglo 
    (Array[0]) en la memoria RAM en 0x100. Entonces Array[1] tiene que estar en 0x104, Array[2] en 0x108 y asi 
    sucesivamente avanzando 4 bytes en memoria (por el tipo de dato), no olvidar que las direcciones de memoria
    estan en hexadecimal (0x es de hexadecimal) y no en decimal.
    0x100 0x104 0x108  0x10C   0x110  0x114
    [0]   [0]   [0]    [0]     [0]    [0]
Pos: 0      1     2      3       4      5

    Los arreglos son rapidos por el hecho de ser memoria secuencial

La relación que tiene un arreglo con los punteros y accesos a las posiciones de un arreglo (Array[0])

    Esto es entrando a un poco de aritmetica de punteros, no es tema como tal de ayp pero sería de utilidad
    para entender a fondo los arreglos.

    Sea int Array[3] = { 10 , 20 , 30 } Un arreglo de tipo entero (4 bytes) de 3 posiciones (4*3 = 12 bytes)
        int *ptr = Array;  Un puntero de tipo entero que apunta a la posicion de Array (Es decir a Array[0] que es 10)
    
    Ahora mostremos las dos formas de acceder a una posicion de un arreglo

    La forma convencional, acceso por indices:

        cout<< Array[1] <<endl; Esto mostrará 20
        cout<< Array[2] <<end; Mostrará 30;

    Acceso con aritmetica de punteros
        cout<< *(ptr + 1)<<endl; esto es equivalente a Array[1], mostrará 20
        La razón de esto es que ptr apunta a la posicion del arreglo Array[0], como tal no se le suma ese + 1
        Se le está sumando el peso en bytes (en este caso 4 bytes) para poder acceder a esa pos
        Como lo mostrado de 0x100 su siguiente posicion (para los enteros) es 0x104 al hacer + 1 no es + 1 como tal
        es + sizeof(tipodedato)
        cout<< *(Array + 1)<<endl; Puedes tratar al arreglo sin "[]" y será usado como el puntero al primer elemento
    
    La formula de acceso:

    i =  index o indice. Esto significa posicion del arreglo. Los indices de un arreglo empiezan siempre en 
    0, y terminan en TamañoDelArreglo - 1. Ejemplo el rango de Array[6] es de 0-5 (ya que 6-1 = 5)

    Array[i] el compilador lo traduce como  *(direcciónBase +  (i * tamañoDelDato))
    el * cuando se usan punteros es para desreferenciar el puntero y tener acceso al elemento
    
    int arr[2]; arr es equivalente  &arr[0], el puntero de un arreglo es la direccion del primer elemento
    *arr es quivalente a arr[0] donde tendremos acceso a lo que hay dentro de esa posicion en el indice 0 (i=0)

Arreglos unidimensionales: Tipos de declaraciones

    1-. Declaracion simple (Cotendo basura)
        int notas[10]; Contiene lo que había en la RAM antes (basura)

    2-. Inicializacion implicita 
        int vocales[5] = {'a', 'e', 'i', 'o', 'u'}; (Se realiza un casteo implicito como hacer int vocal = 'a')
    
    3-.Inicialización parcial (rellena con ceros)
        int vector[10] = {5, 2};  [5, 2, 0, 0, 0, ...]

    4-.Inicialización uniforme (C++11 en adelante):
        int vector[] {1, 2, 3};  El compilador deduce el tamaño (3)     
        Esta es de tipo  direct list initialization
        int vector[] = {1, 2, 3} Exactamente igual al anterior pero esta 
        Esta es de tipo copy list  initialization

    
    5-. Inicializaciones del arreglo donde todas las posiciones sean 0
        int MiArreglo[10] = {};
        int MiArreglo[10] = {0}; Primera posicion 0, las demas se autocompletan como en la 3
        OJO hacer {1} o {cualquier otro numero} no lo inicializará cada posicion con ese numero
        lo que pasará es que la primera posicion será 1 y las demas 0.

TipoDedato Arreglo[Tamaño];
TipoDedato Matriz[x][y];
int 3D[x][y][z];



Matrices en c++
    Una matriz es "Un arreglo de arreglos". Sigue siendo lineal en memoria (pero con trozos de memoria un poco mas grande)
    Se guardan filas tras filas de bytes.
    Imagina que  "{}" es el arreglo que contiene arreglos, y "[]" el arreglo.
    
    {[][][][]} {[][][][]} 

    Ahora, la declaración formal de una matriz en c++

    int Matriz[3][4]; 3 filas y 4 columnas. Puedes verlo de forma Matriz[filas][columnas]

    Inicialización estandar
    int tablero[3][3] = {
        {1, 2, 3},  Fila 0
        {4, 5, 6},   Fila 1
        {7, 8, 9}  Fila 2
    };  
    Esta es una forma bonito de verlo con endl al final de cada fila, visualmente bien pero no es tan necesario
    int tablero[3][3] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    Así tambien se puede hacer, importante las "," para diferenciar las posiciones de filas y cols 
    (elementos del arreglo y del arreglo de arreglos)

Memoria dinamica
    Por bastante parte de la materia te enontraras con arreglos y matrices estaticos (int arr[10] o int tablero[3][3])
    Donde el N del tamaño del arreglo o el N*M de una matriz (N la fila y M las cols) no siempre serán valores estaticos
    como 10, 23 o 0. Pueden ser variables o los puede introducir un usuario por consola

    Si tenemos:

    int  N;
    cin >> N;

    NO PODEMOS HACER: int Arr[N]; Esto está mal por muchas razones

    Tenemos que hacer lo siguiente: 

    Se hace uso de punteros, para reservar espacio en memoria con el new o la cantidad de bytes (N * tipo de dato) a usar
    int* dinámico = new int[N];  Reserva memoria (con basura)
    int* limpio = new int[N]();  Reserva memoria Y la llena de ceros (nota los paréntesis)

    Uso normal
    dinámico[0] = 10;

    IMPORTANTE: Liberar memoria
    Consejo de oro: Por cada new hacer un delete.
    delete[] dinámico;
    delete[] limpio; 

    Para las matrices no es tan diferente. Aquí su declaración dinamica:

    int filas, cols;

    cin >> filas >> cols;

    1. Crear arreglo de punteros (filas)
    cada asterisco "*" representa un "[]" 
    int** crea un puntero de punteros de enteros. 
    int** matriz = new int*[filas];

    2. Crear las columnas para cada fila
    for(int i = 0; i < filas; i++) {
        matriz[i] = new int[cols];
    }

    Usar: matriz[1][2] = 5;

    3. Liberar memoria (Proceso inverso)
    Se borra cada col creada con el for de new y se borra las filas

    for(int i = 0; i < filas; i++) {
        delete[] matriz[i]; // Liberar columnas
    }
    delete[] matriz; // Liberar filas


Acceso de indices: Peligros y  reglas

    En c++ (y diría que todos los lenguajes)  son base 0 (van desde 0 hasta N-1 donde N es el tamaño del arreglo)
    
    c++ no verifica los limites de un arreglo
    Si tengo int Arr[2] e intento acceder a la posicion Arr[6], es decir un acceso fuera de rango
    Ocurrirá algo llamado  comportamiento indefinido. Puede pasar estas cosas:
    1-.Puedes leer basura (datos de otra variable). 
    2-.Puedes corromper la memoria de otra variable. 
    3-.El programa puede crashear (Segmentation Fault) si intentas acceder a memoria que no pertenece a tu programa.
    Siempre checar que cuando manejes arreglos no acceder fuera del rango

    Algo curioso que sucede con los indices negativos:  
        Técnicamente, como arr[i] es *(arr + i), puedes usar índices negativos si el puntero se ha movido previamente.
        Esta practica es 0 recomendable y no deberías usarla en la materia pero es curioso de ver
        int arr[] = {10, 20, 30};
        int* ptr = &arr[1]; // Apunta al 20
        cout << ptr[-1];    // Imprime 10 (retrocede una posición en memoria)
        Igual si haces ptr[-2] ocurrirá lo de hacer un acceso fuera de rango y explota tu pc



Formas de Recorrido en un arreglo:  

    Sea int arr[5] = {1,2,3,4,5};
        int arr[N]; Esto es para mostrarlo con un tamaño general o N 

    A. Recorrido Clásico (Por índice)
    El más común, control total sobre la posición.

        for (int i = 0; i < N; i++) {
            cout << arr[i] << " ";
        }

            B. Recorrido Inverso

            for (int i = N-1; i >= 0; i--) { // Cuidado: i >= 0
                cout << arr[i] << " ";
            }
            Tambien se puede hacer con un for que no retroceda pero haciendo este acceso de indice

            for(int i = 0; i < N; i++){
                cout << arr[N-i-1]; Esa operacion hará que el acceso sea de derecha a izquierda
            }
            N = 5 y i= 0 -> 5-0-1 = 4 Es la ultima posicion. i solo va desde 0 hasta N-1 
            N = 5 y i = N - 1 = 4 (estamos en la ultima iteracion) -> 5-4-1 = 0
            Curioso  

    C. Recorrido por Punteros (Muy eficiente)
    No lo usuarán si no quieren... (No se enseña como tal jskdj)
    for (int* p = arr; p < arr + 5; p++) {
        cout << *p << " "; *p obtiene el valor
    }


    D. Range-based For (C++11 - Moderno)
    Ideal si quieres leer todo y no te importa el índice numérico.
    ESTO NO SE PUEDE USAR NI EN AYP NI AYED, pero es genial saber estas cosas para uso personal
    for (int val : arr) {
        cout << val << " ";  'val' es una copia del elemento
    }
    Usa 'auto&' para modificar los valores originales
    for (auto& val : arr) {
        val *= 2; 
    }

Recorrer una matriz

    for(int i=0; i<filas; i++) { Por cada fila
        for(int j=0; j<cols; j++) { Accede a cada columna
        Accedemos a direcciones contiguas de memoria
        cout << matriz[i][j];  
        }
    }


Pase de parametro de una funcion
    Arreglos:
        Esto se verá bastante en la materia cuando les pasen un arreglo o matriz como parametro de una funcion
        lo que pasa es que cuando se hace este pase de parametro el arreglo se degrada a puntero. 
        Estas dos declaraciones son IDÉNTICAS para el compilador:
        void procesar(int arr[]); 
        void procesar(int* arr);



        No se pasa por copia como harían las variables, esto significa que si modifica el arreglo en la funcion lo modificas afuera.
        void duplicar(int arr[]) {
        arr[0] = 999; Esto cambia el arreglo original fuera de la función
        }
        Dentro de la función, el arreglo ya no sabe cuánto mide.
        sizeof(arr) devolverá el tamaño del puntero (4 u 8 bytes), no el tamaño total del arreglo.

        Por eso es obligatorio pasarse el tamaño del arreglo como un parametro de la funcion
        void imprimir(int arr[], int tamano) {  Pasamos 'tamano' explícitamente
        for(int i = 0; i < tamano; i++) {
            cout << arr[i] << " ";
            }
        }
    
    Matrices: 
        Para matrices multidimensionales, es obligatorio especificar el tamaño de todas las dimensiones excepto la primera.
        El compilador necesita saber "cuánto saltar" para llegar a la siguiente fila.

        Válido: Se especifica columnas (3)
        void imprimirMatriz(int matriz[][3], int filas) {
            for(int i=0; i<filas; i++) {
                for(int j=0; j<3; j++) {
                    cout << matriz[i][j] << " ";
                }
            }
        }

    INVÁLIDO: Error de compilación
    void funcionMala(int matriz[][]); 
*/



int main(){

/*    int  Numeros[] = {1,2,4,5,6,7,8,12,23,23,43,}; //4*5 
            //20/4 = 5
    int N = sizeof(Numeros)/sizeof(int);

    for(int i= 0; i < N; i++){
        cout<<Numeros[i]<<" ";
    }
*/
//int N;
//cout<<"Introduzca el tamaño del arreglo: "; cin>>N;

/*int *Arreglo = new int[N];

    for(int i=0; i<N; i++){
        cout<<"Introduzca el elemento N° "<<i<<" del arreglo: "; cin>>Arreglo[i]; cout<<endl;
    }

    for(int i=0; i<N; i++){
        cout<<"El elemento N° "<<i<<" del arreglo: "<<Arreglo[i] <<endl;
    }

delete[] Arreglo;*/
/*

    int filas, cols;

    cout<<"Introduzca las filas y colunmas de su matriz: "<<endl; cin >> filas >> cols;

    int** matriz = new int*[filas];

    for(int i = 0; i < filas; i++) {
        matriz[i] = new int[cols];
    }
    cout<<"Ingrese los numeros para su matriz"<<endl;
    for(int i= 0; i<filas; i++){
        for(int j = 0; j < cols; j++){
            cin>>matriz[i][j];
        }
    }
    cout<<"Esta es su matriz: "<<endl;
    for(int i= 0; i<filas; i++){
        for(int j = 0; j < cols; j++){
            cout<<matriz[i][j]<<" ";
        }
        cout<<endl;
    }


    for(int i = 0; i < filas; i++) {
        delete[] matriz[i]; // Liberar columnas
    }
    delete[] matriz; // Liberar filas*/

/*
string Palabra = "Hola mundo!";
char Palabra1[100] = {'H', 'o', 'l', 'a'};

string Palabras[] = {"Hola","adios","manolo",};

cout<<Palabras[0][1];

char Matriz[10][10];
*/
/*

bool Flags[3][3] ={
    {0,1,0},
    {1,0,1},
    {false,true,false}
};


for(int i= 0; i< 3; i++){

    for(int j = 0; j< 3; j++){
        if(Flags[i][j]){
            cout<<"*";
        }else{
            cout<<" ";
        }
    }
    cout<<endl;
}

int contadorEncendidos = 0;
for(int i= 0; i< 3; i++){
    for(int j = 0; j< 3; j++){
        if(Flags[i][j])
            contadorEncendidos++;
    }
}
cout<<endl<<"Cantidad de bits encendidos o '*': "<<contadorEncendidos;*/

/*

    int filas, cols;

    cout<<"Introduzca las filas y colunmas de su matriz: "<<endl; cin >> filas >> cols;

    int** matriz = new int*[filas];

    for(int i = 0; i < filas; i++) {
        matriz[i] = new int[cols];
    }
    for(int i= 0; i<filas; i++){
        for(int j = 0; j < cols; j++){
            matriz[i][j] = 1;
        }
    }
    cout<<"Esta es su matriz: "<<endl;
    for(int i= 0; i<filas; i++){
        for(int j = 0; j < cols; j++){
            if(matriz[i][j]){
                cout<<"*";
            }else{
                cout<<" ";
            }
        }
        cout<<endl;
    }


    for(int i = 0; i < filas; i++) {
        delete[] matriz[i]; // Liberar columnas
    }
    delete[] matriz; // Liberar filas*/

    return 0;
}

