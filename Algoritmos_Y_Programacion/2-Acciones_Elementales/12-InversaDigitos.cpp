#include<iostream>  

using namespace std;

float inverse(float d1,float d2,float d3,float d4,float d5,float d6)
{

float sum = (d4 * 100 + d5 * 10 + d6) + (d1/10 + d2/100 + d3/1000);
return sum;
}

int main()
{
float N;
cin>>N;

int aux = N;

int d1 = aux % 10;
aux /= 10;
int d2 = aux % 10;
aux /= 10;
int d3 = aux;

N *= 1000;

int aux2 = int(N) % 1000;

int d4 = aux2 % 10;
aux2 /= 10;
int d5 = aux2 % 10;
aux2 /= 10;
int d6 = aux2;

cout<<inverse(d1,d2,d3,d4,d5,d6)<<endl;

return 0;
}