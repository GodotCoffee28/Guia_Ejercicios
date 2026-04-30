#include<iostream>

using namespace std;

bool existeK(int A[], int K, int N)
{  
    for(int i = 0, j = 1; i < N-1; ++j)
    {  
       if(A[i] + A[j] == K)
       {
        cout<<"Numero usados:"<<A[i]<<" y "<<A[j]<<endl;
        return true;
       } 

        if(j == N)
        {
            i++;
            j = i+1;
        }
    }

    return false;
}

int main()
{
    int A[] = {4,-1,6,8,10,3};

    cout<<existeK(A,2,6);
    return 0;
}

