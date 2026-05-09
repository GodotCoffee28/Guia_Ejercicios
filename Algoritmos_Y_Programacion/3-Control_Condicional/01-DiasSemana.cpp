#include<iostream>

using namespace std;

int Mes_Dias(int day, int mes)
{
    switch(mes)
    {
        case 1: return day; break;
        case 2: return day + 30; break;
        case 3: return day + 58; break; // 30 + 28
        case 4: return day + 88; break; // 30 + 28 + 31
        case 5: return day + 118; break;
        case 6: return day + 148; break;
        case 7: return day + 178; break;
        case 8: return day + 208; break;
        case 9: return day + 238; break;
        case 10: return day + 268; break;
        case 11: return day + 298; break;
        case 12: return day + 328; break;
        default: return -1; break;
    }
}

void DiasName(int N)
{
    N %= 7;

    switch(N)
    {
        case 1: cout<<"Lunes"; break;
        case 2: cout<<"Martes"; break;
        case 3: cout<<"Miercoles"; break;
        case 4: cout<<"Jueves"; break;
        case 5: cout<<"Viernes"; break;
        case 6: cout<<"Sabado"; break;
        case 0: cout<<"Domingo"; break;
    }
}

int main()
{
    int fec1,fec2,dd1,dd2,mm1,mm2,age1,age2;

    //Fechas
    cout<<"Fecha 1:";
    cin>>fec1;
    cout<<"Fecha 2";
    cin>>fec2;

    //Separar
    age1 = fec1 % 10000;
    fec1 /= 10000;
    mm1 = fec1 % 100;
    fec1 /= 100;
    dd1 = fec1; 

    age2 = fec2 % 10000;
    fec2 /= 10000;
    mm2 = fec2 % 100;
    fec2 /= 100;
    dd2 = fec2; 

    // Transformar a dias

    int aux1, aux2;

    aux1 = 365 * age1;
    aux2 = 365 * age2;

    // Sumar

    int Sum1, sum2;

    Sum1 = aux1 + Mes_Dias(dd1,mm1);
    sum2 = aux2 + Mes_Dias(dd2,mm2);

    int Rest = abs(Sum1 - sum2);

    int Mayor, Menor;

    if(Sum1 > sum2)
    {
        Mayor = Sum1;
        Menor = sum2;
    } else
        {
        Menor = Sum1;
        Mayor = sum2; 
        }

    if(Rest%2==0)
    {
        DiasName(Menor);
    } else
        {
            DiasName(Mayor);
        }

   return 0;     
}