#include<iostream>
#include<cmath>

using namespace std;

int Armstrong(int d1, int d2, int d3, int d4, int d5)
{
if(d1 == 0 && d2 == 0 && d3 == 0 && d4 == 0) return d5;
else if(d1 == 0 && d2 == 0) return pow(d3,3) + pow(d4,3) + pow(d5,3);
else if(d1 == 0) return pow(d2,4) + pow(d3,4) + pow(d4,4) + pow(d5,4);

return pow(d1,5) + pow(d2,5) + pow(d3,5) + pow(d4,5) + pow(d5,5);
}

int main()
{
int d1,d2,d3,d4,d5,N,aux;
cout<<"Ingrese numero de maximo 5 digitos: ";
cin>>N;

aux = N;

d5 = N % 10;
N /= 10;
d4 = N % 10;
N /= 10;
d3 = N % 10;
N /= 10;
d2 = N % 10;
N /= 10;
d1 = N;

if(aux == Armstrong(d1,d2,d3,d4,d5)) cout<<"Es Armstrong";
else cout<<"No lo es";

    return 0;
}