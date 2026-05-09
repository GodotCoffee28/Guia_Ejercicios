#include <iostream>

using namespace std;

bool esBisiesto(int age)
{
int ultimo_par = age % 100;

if(age % 4 == 0 && ultimo_par != 0) return true;
else if(age % 400 == 0 && age % 100 == 0 && ultimo_par == 0) return true;

    return false;
}

int dias_trans(int day, int mes, int age)
{
switch(mes)
    {
        case 1: return day; break;
        case 2: return day + 30; break;
        case 3: return day + 58 + esBisiesto(age); break;
        case 4: return day + 88 + esBisiesto(age); break;
        case 5: return day + 118 + esBisiesto(age); break;
        case 6: return day + 148 + esBisiesto(age); break;
        case 7: return day + 178 + esBisiesto(age); break;
        case 8: return day + 208 + esBisiesto(age); break;
        case 9: return day + 238 + esBisiesto(age); break;
        case 10: return day + 268 + esBisiesto(age); break;
        case 11: return day + 298 + esBisiesto(age); break;
        case 12: return day + 328 + esBisiesto(age); break;
        default: return -1; break;
    }
}

int main()
{
    int day, mes, age, N;
    cin>>N;

    day = N % 100;
    N /= 100;
    mes = N % 100;
    N /= 100;
    age = N;

    int dias_faltantes = (358 + esBisiesto(age)) - dias_trans(day,mes,age);

    cout<<dias_faltantes;

    return 0;
}    