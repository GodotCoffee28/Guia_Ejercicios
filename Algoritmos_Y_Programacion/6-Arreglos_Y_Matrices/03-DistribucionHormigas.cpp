#include<iostream>

using namespace std;


void distributeAnts(int &x,int &y,int &z,int N, char A[3][3])
{
if(x < N*N || y < N*N || z < N)
    {
        return ;
    }
    
for(int i = 0; i < N; i++)
    { 
        for(int j = 0; j < N; j++)
        {
            if(i == j)
            {
                A[i][j] = 'C';
                z--;
            } else if(i > j)
                {
                    A[i][j] = 'A';
                    x--;
                } else  
                    {
                        A[i][j] = 'B';
                        y--;
                    }   
        }
    }

}


int main()
{
char A[3][3] = {{' ',' ',' '},{' ',' ',' '},{' ',' ',' '}};

int x = 10, y = 10, z = 3, N = 3;

distributeAnts(x,y,z,N,A);

cout<<x<<" "<<y<<" "<<z<<endl;

for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            cout<<A[i][j];
        }
        cout<<endl;
    }    
return 0;
}
