#include<iostream>

using namespace std;

bool col(bool A[5][5], int N)
{
for(int i = 0; i < N; i++)
{
    int count = 0;
    for(int j = 0; j < N; j++)
    {
        if(A[j][i] == 1)
        {
            count++;
        }
    }
    
    if(count == 5)
    {
        return true;
    }
}
return false;
}

bool fil(bool A[5][5], int N)
{
for(int i = 0; i < N; i++)
{
    int count = 0;
    for(int j = 0; j < N; j++)
    {
        if(A[i][j] == 1)
        {
            count++;
        }
    }
    if(count == 5)
    {
        return true;
    }
}
return false;
}

bool diagonales(bool A[5][5], int N)
{
    for(int i = 0, count = 0; i < N; i++)
    {
        if(A[i][i] == 1){
            count++;
        }
        if(count == 5)
        {
        return true;
        }
    }

    for(int i = 0, j = N-1,count = 0; i < N; i++, j--)
    {
        if(A[i][j-1] == 1)
        {
            count++;
        }
        if(count == 5)
        {
        return true;
        }
    }

    return false;
}

void bingo(bool A[5][5],int N)
{
    if(diagonales(A, N) || col(A, N) || fil(A, N))
    {
        cout<<"Bingo";
    } else
        {
            cout<<"No gana";
        }
}

int main()
{
bool A[5][5] = {{1,0,0,0,0},{0,1,0,0,0},{0,0,1,0,0},{0,0,0,1,0},{1,0,0,0,1}};
int N = 5;

bingo(A,N);

return 0;
}