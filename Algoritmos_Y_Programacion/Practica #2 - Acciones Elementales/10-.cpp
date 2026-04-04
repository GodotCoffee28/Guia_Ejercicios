/*10. José y Pedro son dos ranas. José puede dar saltos de J centímetros y
Pedro puede dar saltos de P centímetros. Suponiendo que ambas ranas
comienzan a saltar en el mismo punto (y en la misma dirección), haga
un algoritmo que determine si las ranas coincidirán en el mismo punto en
algún momento antes de que José de K saltos.*/

#include<iostream>
using namespace std;

int main(){

    int P_cm = 0, J_cm = 0, K_saltos_J = 0, mcd = 0;
    cin >> P_cm >> J_cm >> K_saltos_J >> mcd;

    int mcm = (P_cm * J_cm) / mcd;
    int alcance_Jose = J_cm * K_saltos_J;

    cout << (mcm <= alcance_Jose) << endl; // 1 si coinciden, 0 si no
    return 0;
}