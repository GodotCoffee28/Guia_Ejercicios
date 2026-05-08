    #include<iostream>
    #include<string>

    using namespace std;
    /*Dado un número entero positivo o nulo (en base decimal), construya un algoritmo recursivo que tenga por resultado otro número entero cuyo valor sea la representación en binario (en base 2) del valor dado. Haga el mismo proceso para base 16.*/
    void BinaryBase2(int n);
    long long decimalABinarioRecursivo(int n, long long binarioAcumulado=0, long long multiplicador=1);

    int main(){
        int n;
        cout<<"Introduzca su numero a transformar a binario base 2: "; cin>>n;
        cout<<"Su numero en binario en base 2 es: "<<decimalABinarioRecursivo(n);
        cout << endl; // Añadido para un salto de línea después del resultado
        return 0;
    }


/*    long long decimalABinarioRecursivo(int n, long long binarioAcumulado, long long multiplicador) {
        if (n == 0) {
            return binarioAcumulado;
        } else {
            int residuo = n % 2;
            long long nuevoBinarioAcumulado = binarioAcumulado + (residuo * multiplicador);
                return decimalABinarioRecursivo(n / 2, nuevoBinarioAcumulado, multiplicador * 10);
        }
    }
*/
long long decimalABinarioRecursivo(int n, long long binarioAcumulado, long long multiplicador) {
    if (n == 0) return binarioAcumulado;
        return decimalABinarioRecursivo(n / 2, (binarioAcumulado + ((n % 2) * multiplicador)), multiplicador * 10);
}
