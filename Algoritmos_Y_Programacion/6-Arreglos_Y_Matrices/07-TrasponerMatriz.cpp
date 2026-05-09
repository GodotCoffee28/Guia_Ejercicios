#include<iostream>

using namespace std;

void transponerMatriz(int A[3][3], int N)
{
    for(int i = 0; i < N; ++i)
    {
        for(int j = i + 1; j < N; ++j)
        {
            int aux = A[i][j];
            A[i][j] = A[j][i];
            A[j][i] = aux;
        }
    }
}

void print(int A[3][3], int N)
{
    for (int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cout<<A[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}

int main()
{
 int A[3][3] = { {1, 5, 3}, {2, 3, 7}, {4,5,6} };
int N = 3;

print(A,N);
transponerMatriz(A,N);
print(A,N);
    return 0;
}