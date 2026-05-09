#include<iostream>

using namespace std;

void sumArr(int A[], int N,int &a, int &b, float &countPar, float &countImp)
{
for(int i = 0; i < N; i++)
    {
        if(i%2 == 0)
        {
        a += A[i];
        countPar++;
        } else
            {
            b += A[i];
            countImp;
            }
    }
}

bool isStable(int A[], int N)
{
    int sumPar = 0, sumImp = 0;
    float countPar = 0, countImp = 0;

sumArr(A,N,sumPar,sumImp,countPar,countImp);

float promPar = sumPar / countPar;
float promImp = sumImp / countImp;

if(promPar > promImp && sumPar == sumImp)
{
    return true;
} else
    {
        return false;
    }
}
