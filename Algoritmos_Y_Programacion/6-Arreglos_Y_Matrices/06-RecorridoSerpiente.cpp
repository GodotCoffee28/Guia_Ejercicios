#include<iostream>

using namespace std;



int main()
{
    int A[3][3] = {{9,5,7},{6,3,8},{2,4,1}};
    int N = 3;

    int sum = A[0][0];
    int sign = 1;
    
    for(int i = 0; i < N; i++)
    {
        if(i%2 == 0)
        {
            for(int j = 0; j < N; j++)
            {
                if(i == 0 && j == 0)
                {
                    continue;
                }
                sum += A[i][j] * sign;
                sign *= -1;
            }
        } else
            {
            for(int j = N-1; j >= 0; j--)
            {
                sum += A[i][j] * sign;
                sign *= -1;  
            }
            }   
    }

    cout<<sum;
}