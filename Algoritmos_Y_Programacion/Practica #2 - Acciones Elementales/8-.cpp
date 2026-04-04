/*Supongamos un reloj analógico (de agujas). Dada lo hora exacta (horas y
minutos), escriba un algoritmo que calcule el ángulo entre ambas agujas.
Por ejemplo, a las 3:00 el ángulo será 90 grados. A las 3:15 el ángulo será
7,5 grados */

#include<iostream>
#include<math.h>
using namespace std;


int main(){
    //Primero: Modelamos los grados del angulo de la manecilla de las horas:
        //360° en un reloj. Un reloj tiene 12 horas
        float Grados_H_Hora = 360 / 12; //360°/12 H = 30° cada hora 


        float Grados_H_Minuto = Grados_H_Hora / 60; // 30° cada 60 Minutos / 60 minutos -> 0.5 cada Minuto 
        
    //Segundo: Modelamos los grados  del angulo de la manecilla de los minutos:
        //Hay 360 grados en un reloj en 60 minutos
        float Grados_M_Minuto = 360 / 60; // 360° / 60 Minutos -> 6° cada minuto
        //Teniendo esto ya podemos proseguir con lo demas
    
    //Tercero: Obtenemos los datos de entrada y calculamos

        int hour = 0;
        int minutes = 0;
        cin>>hour>>minutes;
        // Calculamos los grados de la manecilla de las horas. 
        //Cada hora que tengamos, son 30 grados
        float Grados_H = hour * Grados_H_Hora; 
        // Le sumamos los grados que se mueve  por los minutos. 
        Grados_H += minutes * Grados_H_Minuto; 

        //Calculamos los grados de la manecilla de los minutos
        //Cada minuto que tengamos, son 6 grados
        float Grados_M = minutes * Grados_M_Minuto;

    //Cuarto: Teniendo los grados de ambas manecillas
        //Se Restana ambos grados y la diferencia de estos (o el resultado) será los grados que hay entre una manecilla y otra
        //Y para evitar numeros negativos el valor absoluto ||
        float d = abs(Grados_H - Grados_M);
        //Para obtener el angulo menor sin que sea negativo ni se pase de 180, tomamos el minimo valor entre d o 360-d

        float angulo = min(d,360-d);
        
    cout<<angulo;


    return 0;
}