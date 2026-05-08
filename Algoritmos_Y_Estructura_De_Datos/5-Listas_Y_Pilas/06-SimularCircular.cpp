#include<iostream>
#define REPEAT(n) for(int i=0; i < (n); i++)
using namespace std;
/*Implemente una lista con arreglo que simule una lista 
circular de caracteres con n posiciones y dados dos enteros m e i, 
imprima m valores a partir de la posición i.*/
class List{
    private:
    struct Node{
        string data;
        Node* next;
        Node(string d, Node* n=nullptr): data(d), next(n){}
    };

    Node* head;
    int size;
    public:
    typedef Node* tPosition;
    List(): size(0){
        head = new Node("");
        head->next = head;
    }
    ~List(){
        head = nullptr;
    }
    int Size(){
        return size;
    }
    bool IsEmpty()const{
        return size==0;
    }
    tPosition first()const{ //Primer dato valido o primer nodo con datos
        if(IsEmpty()) return head;
        return  head->next;
    }
    void next(tPosition& node){
        node = node->next;
    }
    void insert(const string& data){
        if(IsEmpty()){
            head->next = new Node(data, head);
        }else{
            tPosition current = first();
            while(current->next != head){
                next(current);
            }
            tPosition newNode = new Node(data, head);
            current->next = newNode;
        }
        size++;
    }
    void printFromPosition(int mValues, int iPosition){
        if(IsEmpty() || mValues <=0) return;

        tPosition current = first();
        
        int starPosition = iPosition % size;

        for(int count = 0; count < starPosition; ++count ){
            next(current);
        }
        for(int count =0; count < mValues; ++count){
            //if(current == head) next(current);
            printNode(current);
            next(current);
        }
        cout<<endl;
    }
    void printNode(tPosition node){
        cout<<node->data<<" ";
    }
};

int main(){
    List MyList;
    MyList.insert("Hoola");
    MyList.insert("que onda");
    MyList.insert("porque");
    MyList.insert("si");
    
    MyList.printFromPosition(4, 2);
}