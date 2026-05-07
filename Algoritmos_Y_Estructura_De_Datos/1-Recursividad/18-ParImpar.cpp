#include<iostream>
using namespace std;

bool esPar(int);
bool esImp(int);

int main(){
    long long n;
    cout << "Coloque su numero" << endl;
    cin >> n;

    if (n < 0) {
        n*=-1;
    } 
    if (esPar(n)) {
        cout << "Es Par" << endl;
    } else {
        cout << "Es Impar" << endl;
    }
    
    return 0;
}

bool esPar(int n){
    if(n == 0){
        return true;
    }
        return esImp(n - 1);
}

bool esImp(int n){
     if(n == 0){
        return false;
    }
        return esPar(n - 1);
}