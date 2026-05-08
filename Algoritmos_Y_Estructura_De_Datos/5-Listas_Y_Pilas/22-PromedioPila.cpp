/*Dada una pila, se desea conocer el promedio de los elementos que ella almacena.
 Como restricción la pila puede ser recorrida una sola vez.*/

 #include <iostream>
 #include <stack>
 using namespace std;

template<typename T>
float Prom(stack<T> p){
    int sum=0;
    int size = p.size();
    while (!p.empty()){
        sum+=p.top();
        p.pop();
    }

    return sum/size;
}
template<typename T>

void printstack(stack<T> p){
    while(!p.empty()){
        cout<<p.top()<<endl;
        p.pop();
    }
}

int main(){
    stack<int> p;
    for(int i=1; i < 20 ; i++) p.push(i);
    cout<<"PILA ACTUAL: "<<endl;
    printstack(p);
    cout<<"EL PROMEDIO DE LOS VALORES DE LA PILA ES: "<<Prom(p);

    return 0;
}