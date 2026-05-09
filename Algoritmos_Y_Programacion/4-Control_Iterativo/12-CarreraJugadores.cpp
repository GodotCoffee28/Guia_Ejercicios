#include<iostream>
#include<cmath>

using namespace std;

int random();

bool primo(int a)
{
    int aux = sqrt(a);
    for(int i = 2; i <= aux; i++)
    {
        if(a%i == 0)
        {
            return false;
        }
    }
    return true;
}


int juego(int jugadores[], int NumJugadores)
{
    for(int i = 0; i < NumJugadores; i++)
    {
        jugadores[i] += random();

        if(jugadores[i]%3==0)
        {
            jugadores[i] -= 5;
        } else if(jugadores[i]%7==0)
            {
             jugadores[i] += random();
            }else if(primo(jugadores[i]))
                {
                    jugadores[i] += 10;
                }

        if(jugadores[i] >= 100)
        {
            return i;
        }        
    }
}

