#include<iostream>

using namespace std;

int mcm(int a, int b)
{
    int mcm = 0;
for(int i = 2; i <= a * b; i++)
{
    if(i%a == 0 && i%b == 0)
    {
        return i;
    }
}
    return -1;
}

int lightSync(int *A, int N)
{
    int result = A[0];
    for(int i = 1; i < N; i++)
    { 
        result = mcm(result, A[i]);
    }
    return result;
}

int main()
{
    int N;
    cin>>N;

    int *A = new int[N];

    for(int i = 0; i < N; i++)
    {
        int aux;
        cin>>aux;
        A[i] = aux;
    }

    cout<<lightSync(A,N)<<endl;
}