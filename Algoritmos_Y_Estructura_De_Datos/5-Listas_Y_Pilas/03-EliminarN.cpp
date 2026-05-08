/*3-Dada una lista con arreglos de enteros y número entero n, 
implementar una función donde se eliminen todos los números n de la lista.*/
/*5-Implementar una función mezcla2 que tenga como parámetros dos listas con arreglos
 de enteros ordenados de menor a mayor y que devuelva una 
nueva lista con arreglo con la unión de ambas listas anteriores con sus elementos ordenados de la misma forma.*/

#include<iostream> 
#include<exception>
#define REPEAT(n) for(int i = 0; i < (n); ++i)
using namespace std;
//tenemos que im*plementar una lista que se enlaza una ves donde cada dato es un arreglo de enteros
class List{
    private:
    struct Node{
        int* datos; //Cada nodo tiene un apuntador de enteros (para el arreglo de entero)
        int tamanio; //cada nodo necesita un tamaño para su arreglo
        Node* next; //Cada nodo apunta a el siguiente nodo
        //Constructor donde se le pasa el tamaño y por defecto null para el siguiente nodo y null para el arreglo si no se nos pasa
        Node(int t, //Tamaño
            Node* n=nullptr, //n de siguiente pero si no nos pasan siguiente nodo entonces apuntamos a null
            int *d=nullptr //Crucial, si no nos pasan el arreglo de enteros se tiene como null 
            ): tamanio(t), next(n){  //inicializamos el tamaño con el que nos pasen y el apuntador del siguiente nodo con el que nos pasen o con nulo
            if(tamanio > 0){ //si tenemos almenos un elemento en el arreglo
                datos = new int[tamanio]; //le creamos dinamicamente el tamaño a los datos o el arreglo de enteros
                    if(d != nullptr){ //Si d no es nulo almacenamos el arreglo que nos pasen al arreglo del nodo
                        REPEAT(tamanio){
                            datos[i] = d[i]; 
                        }
                    } else{ //si no nos pasaron ningun arreglo d es nulo y por defecto lo inicializamos con 0's
                        REPEAT(tamanio){
                            datos[i] = 0; 
                        }
                    }
            } else { //Si no tenemos almenos un elemento en el arreglo este sera nulo
                datos = nullptr;
            }
        }
        ~Node(){ //para destruir nuestro objeto de tipo entero
            delete[] datos; 
        }
    };
    Node* head; //nodo centinela que sera el primero o la cabeza en la lista
    Node* tail; //Nodo centinela que sera el ultimo o la cola en la lista
    int size; //tamaño de la lista
    public:
    typedef Node* tPosition; // para q sea bonito
    List(): size(0){ //constructor por defecto de la clase donde inicializamos el tamaño con 0
        tail = new Node(0); //A la cola le pasamos por defecto tenemos que el arreglo no tendra elementos y tail->next sera null por defecto
        head = new Node(0, tail); //la cabeza tampoco tendra elementos y head->next sera la cola, el siguiente a la cabeza por defecto sera la cola
        size = 0; //tamaño 0
    }
    List(const List& other) : size(0) { // Inicializa tu nueva lista
        tail = new Node(0); // Crea los nuevos centinelas
        head = new Node(0, tail);
        size = 0; // El tamaño se ajustará al copiar los nodos

        tPosition current_other = other.first(); // Empieza a copiar desde el primer nodo de datos de 'other'
        while (current_other != other.Tail()) { // Recorre todos los nodos de datos de 'other'
            // Usa PushBack para añadir una copia profunda del nodo actual de 'other'
            PushBack(current_other->tamanio, current_other->datos);
            next(current_other);
        }
    }
    ~List(){ //destructor de la clase
        Node* current = head; //utilizaremos current para movernos en el nodo para destruirlo
        while(current != nullptr){ // mientras que current no sea nulo nos movemos, sera nulo cuando ya hayamos borrado todo
            Node* temp = current->next; // guardamos un temporal porque es necesario tener el siguiente del actual/current
            delete current; //borramos current actual
            current = temp; //Movemos current al siguiente en la lista
        }
        tail = nullptr; //para que no queden punteros colgantes
        head = nullptr;
        size = 0;//buena practica
    }
    int Size(){
        return size;
    }
    bool IsEmpty()const{
        return size==0;
    }
    tPosition first()const{ //Primer dato valido o primer nodo con datos
        return  (head->next != tail) ? head->next:tail; 
    }
    tPosition last() const { // Ultimo dato valido o ultimo nodo con datos
    if (IsEmpty()) { // Si la lista está vacía, el "último" nodo de datos es conceptualmente 'tail'.
        return tail;
    }
    
    tPosition current = first();
    while (current->next != tail) { 
        next(current);
    }
    return current; 
    }
    tPosition Tail()const{ // La cola: hola
        return tail;
    }
    void next(tPosition& pValue)const{
        if(pValue != tail){
            pValue = pValue->next;
        }
    }
    int* &get(tPosition v){
        return v->datos;
    }

    void insert(int* ArrInsertar, tPosition PosicionInsertar, int TamanoArr){
        //el tamaño no puede ser negativo
        if(TamanoArr < 0){
            throw invalid_argument("No puedes tener un tamaño negativo");
        }
        tPosition current = head; //con lo que nos moveremos en la lista
        //bucle para encontrar el nodo anterior a posicion a insertar con una condicion para no pasar dle final de la lista
        while(current->next != PosicionInsertar && current->next != nullptr){
            next(current);
        }

        if(current->next != PosicionInsertar){ //si se sale de la lista y es que no encontro la posicion
            cerr<<"Error: La posicion dada no esta en la lista";
            return;
        }
        current->next = new Node(TamanoArr, PosicionInsertar, ArrInsertar);
        size++;
    }
    void Delete(tPosition PosicionEliminar){
        if(PosicionEliminar == nullptr){
            cerr<<"Error: No se puede eliminar una posicion nula";
            return;
        }
        if(PosicionEliminar == tail || PosicionEliminar == head){
            cerr<<"Error: No se puede eliminar un nodo centinela (head/tail)";
            return;
        }
        tPosition current = head;
        while(current->next != PosicionEliminar && current->next !=nullptr){
            next(current);
        }
        if(current->next != PosicionEliminar){ //si se sale de la lista y es que no encontro la posicion
            cerr<<"Error: La posicion dada no esta en la lista";
            return;
        }
        current->next = PosicionEliminar->next;
        delete PosicionEliminar;
        size--;
    }
    void printFirst(){
        if(IsEmpty()){
            cout<<"[]"<<endl;
            return;
        }
        tPosition firstNode = first();
        int* Arraydata = get(first());
        int ArraySize = firstNode->tamanio;
        cout<<"[";
        REPEAT(ArraySize){
            cout<<Arraydata[i];
            if(i < ArraySize-1) cout<<", ";
        }
        cout<<" ]"<<endl;
    }

    void printLast(){
        if(IsEmpty()){
            cout<<"[]"<<endl;
            return;
        }
        tPosition lastNode = first();
        while(lastNode->next != tail){
            next(lastNode);
        }
        int* Arraydata = get(lastNode);
        int ArraySize = lastNode->tamanio;
        cout<<"[";
        REPEAT(ArraySize){
            cout<<Arraydata[i];
            if(i < ArraySize-1) cout<<", ";
        }
        cout<<" ]"<<endl;
    }

    void printAll(){
        if(IsEmpty()){
            cout<<"{ [ ] }"<<endl;
            return;
        }
        tPosition current = first();
        cout<<"{";
        while(current != tail){
            int* CurrentArray = get(current);
            int CurrentSize = current->tamanio;
            cout<<" [";
            REPEAT(CurrentSize){
                cout<<CurrentArray[i];
                if(i < CurrentSize-1) cout<<", ";
            }
            cout<<" ]";
            if(current->next != tail) cout<<", "; 
            next(current);
        }
        cout<<" }"<<endl;
    }
    void printYourNode(tPosition YourNode){
        if(YourNode==nullptr){
            cerr<<"Error: no puedes imprimir un nodo invalido"<<endl;
            return;
        }
        if(YourNode == head || YourNode == tail){
            cerr<<"Error: no puedes imprimir los nodos centinelas (head/tail)"<<endl;
            return;
        }

        int* Arraydata = get(YourNode);
        int ArraySize = YourNode->tamanio;
        cout<<"[";
        REPEAT(ArraySize){
            cout<<Arraydata[i];
            if(i < ArraySize-1) cout<<", ";
        }
        cout<<" ]"<<endl;
    }
    void clear(){
        tPosition current = first();
        while(current != tail){
            tPosition temp = current->next;
            delete current;
            current = temp;
        } 
        head->next = tail;
        size = 0;
    }
    tPosition find(int n){
        tPosition current = first();
        while(current != tail){
            int* CurrentArray = get(current);
            int CurrentSize = current->tamanio;
            REPEAT(CurrentSize){
                if(CurrentArray[i]==n){
                    return current;
                }
            }
            next(current);
        }
        return tail;
    }
    void deleteByValue(tPosition node, int n){
        if(node==nullptr || node->tamanio <=0){
            return;
        }
        int* OldArray = get(node);
        int OldSize = node->tamanio;
        int contN=0;
        REPEAT(OldSize){
            if(OldArray[i]==n){ 
                OldArray[i] = INT_MIN;
                contN++;
            }
        }
        if(contN==0){
            return;
        }
        int NewSize = OldSize - contN;
        int* NewArray = new int[NewSize];
        int index = 0;
        REPEAT(OldSize){
            if(OldArray[i] != INT_MIN){
                NewArray[index] = OldArray[i];
                index++;
            }
        }
        delete[] OldArray;
        node->datos = NewArray;
        node->tamanio = NewSize;
    }
    void SwapDatas(int &data1, int &data2 ){
        int aux = data1;
        data1  = data2;
        data2 = aux;
    }
    void OrderAscendent(tPosition node){
        if (node == nullptr || node->tamanio <= 1) { // <=1 porque 0 o 1 elemento ya están ordenados
        return;
        }
        int* CurrentArray = get(node);
        int CurrentSize = node->tamanio;
        bool IsOrderer = false;
        while(!IsOrderer){
            IsOrderer = true;
            REPEAT(CurrentSize-1){
                if(CurrentArray[i] > CurrentArray[i+1]){
                SwapDatas(CurrentArray[i], CurrentArray[i+1]);
                IsOrderer = false;
                } 
            }
        }
    }
    void OrderAscendentAll(){
        /*tPosition current = first();
        while(current->next != tail){
            OrderAscendent(current);
            next(current);
        }*/
        for(tPosition current = first(); current != tail; next(current)){
            OrderAscendent(current);
        }
    }
    void OrderDescendent(tPosition node){
        if (node == nullptr || node->tamanio <= 1) { // <=1 porque 0 o 1 elemento ya están ordenados
        return;
        }
        int* CurrentArray = get(node);
        int CurrentSize = node->tamanio;
        bool IsOrderer = false;
        while(!IsOrderer){
            IsOrderer = true;
            REPEAT(CurrentSize-1){
                if(CurrentArray[i] < CurrentArray[i+1]){
                SwapDatas(CurrentArray[i], CurrentArray[i+1]);
                IsOrderer = false;
                } 
            }
        }
    }
    void OrderDescendentAll(){
        /* tPosition current = first();
        while(current->next != tail){
            OrderDescendent(current);
            next(current);
        }*/
        for(tPosition current = first(); current != tail; next(current)){
            OrderDescendent(current);
        }
    }
    bool IsOrderedList()const{
        if(IsEmpty()){
            return true;
        }
        for(tPosition current = first(); current->next != tail; next(current)){
            if(!IsOrderedNode(current)) return false;
        }
        return true;
    }
    bool IsOrderedNode(tPosition node)const{
        if (node == nullptr || node->tamanio <= 1) {
            return true;
        }
        REPEAT(node->tamanio-1){
            if(node->datos[i] > node->datos[i+1]) return false;
        }
        return true;
    }
    void PushBack(int ArrSize, int* Arr){
        insert(Arr, tail, ArrSize);
    }
    void PushFront(int ArrSize, int* Arr){
        insert(Arr, head, ArrSize);
    }
    void PopBack(){
        if(IsEmpty()){
            cerr<<"Error: Lista vacia. No se puede hacer un PopBack"<<endl;
        }
        Delete(last());
    }
    void PopFront(){
        if(IsEmpty()){
            cerr<<"Error: Lista vacia. No se puede hacer un PopFront"<<endl;
        }
        Delete(first());
    }

};

    int GetFirstArray(List::tPosition Nodo){
        if(Nodo == nullptr || Nodo->tamanio <= 0 || Nodo->datos == nullptr){
            throw runtime_error("Intento de acceder a un nodo, o arreglo invalido o tamaño invalido");
        }
        return Nodo->datos[0];
    }
List mezcla2( const List& n1, const List& n2) {
    if(!n1.IsOrderedList() || !n2.IsOrderedList()){
        cerr<<"No estan ordenadas tus dos listas"<<endl;
        return List();
    }
    List NewList = List();

    List::tPosition current_n1 = n1.first();
    List::tPosition current_n2 = n2.first();
    List::tPosition tail_n1 = n1.Tail();
    List::tPosition tail_n2 = n2.Tail();
    
    while(current_n1 != tail_n1 && current_n2 != tail_n2){
        if(GetFirstArray(current_n1) <= GetFirstArray(current_n2)){
            NewList.PushBack(current_n1->tamanio, current_n1->datos);
            n1.next(current_n1);
        } else{
            NewList.PushBack(current_n2->tamanio, current_n2->datos);
            n2.next(current_n2);
        }
    }
    while(current_n1 != tail_n1){
        NewList.PushBack(current_n1->tamanio, current_n1->datos);
        n1.next(current_n1);
    }
    while(current_n2 != tail_n2){
        NewList.PushBack(current_n2->tamanio, current_n2->datos);
        n2.next(current_n2);
    }
    return NewList;
}


int main(){
    List MisEnteros;
    cout<<"---LISTA DE ENTEROS CREADA---"<<endl;
    cout<<"LA LISTA ESTA VACIA?"<< (MisEnteros.IsEmpty() ? " Si\n" : " No\n");
    MisEnteros.printAll();
    MisEnteros.printFirst();
    MisEnteros.printLast();
    int Arreglo1[] = {3,2,7,8,4};
    int Arreglo2[] = {6,7,8,9,7, 7, 69, 10 ,3};
    int Arreglo3[] = {11,1,13,14,9, 2, 4 , 19 ,17 ,18};
    
    int size1 = sizeof(Arreglo1) / sizeof(Arreglo1[0]);
    int size2 = sizeof(Arreglo2) / sizeof(Arreglo2[0]);
    int size3 = sizeof(Arreglo3) / sizeof(Arreglo3[0]);
    List MisOtrosEnteros;
    MisOtrosEnteros.PushBack(size1,Arreglo1);
    MisOtrosEnteros.PushBack(size2,Arreglo2);
    MisOtrosEnteros.PushBack(size3,Arreglo3);

    cout<<"\n---INSERTANDO CONJUNTO DE ENTEROS AL PRIMER LISTA DE ENTEROS---\n";
    MisEnteros.insert(Arreglo1, MisEnteros.first(), size1);
    MisEnteros.insert(Arreglo2, MisEnteros.last(), size2);
    MisEnteros.insert(Arreglo3, MisEnteros.last(), size3);
    cout<<"TODOS LOS NODOS: ";MisEnteros.printAll();
    cout<<"EL PRIMER NODO: ";MisEnteros.printFirst();
    cout<<"EL ULTIMO NODO: ";MisEnteros.printLast();
    
    cout<<"\n---INSERTANDO CONJUNTO DE ENTEROS A LA SEGUNDA LISTA DE ENTEROS---\n";
    cout<<"TODOS LOS NODOS: ";MisOtrosEnteros.printAll();
    cout<<"EL PRIMER NODO: ";MisOtrosEnteros.printFirst();
    cout<<"EL ULTIMO NODO: ";MisOtrosEnteros.printLast();
    /*int n=5;
    cout<<"---BUSCANDO Y ELIMINANDO NUMERO "<<n<<" ---"<<endl;
    MisEnteros.printYourNode(MisEnteros.find(n));
    MisEnteros.printAll();
    MisEnteros.OrderAscendentAll();
    /*while(MisEnteros.find(n)){
        MisEnteros.deleteByValue(MisEnteros.find(n), n);
    }

    cout<<endl;
    MisEnteros.printAll();
    MisEnteros.clear();*/  
    MisEnteros.OrderAscendentAll();
    MisOtrosEnteros.OrderAscendentAll();
    cout<<"----MOSTRANDO LA MEZCLA DE MIS ENTEROS DOS VECE----"<<endl;
    List OtrosEnteros = List(mezcla2(MisEnteros,MisOtrosEnteros));

    OtrosEnteros.printAll();
return 0; 

}