#include<iostream>

using namespace std;

int f(int a, int b)
{
    return 2*b-a;
}

int polynomialFolding(int A[], int N)
{
    int tamInicial = N;

    while(tamInicial > 1){
        int newTam = tamInicial / 2;

        for(int i = 0; i < newTam;i++)
        {
            int a = A[i];
            int b = A[tamInicial-1-i];
            A[i]=f(a,b);
        }
        
        tamInicial = newTam;
    } 
    return A[0];
}

int main()
{
int arr1[] = {1, 2, 3, 4};
int size1 = 4;

cout<<polynomialFolding(arr1,size1);
}