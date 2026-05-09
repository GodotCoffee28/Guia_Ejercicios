#include<iostream>
#include<math.h>
using namespace std;
/*7. Obtener todos los números de m cifras (m <= 9), todas ellas distintas de cero y distintas entre sí, de tal manera que el 
numero formado por las primeras n cifras, cualquiera que sea n (n <= m) sea múltiplo de n. Por ejemplo, para m = 4 
son números válidos, entre otros, los siguientes: 1236, ya que 1 es múltiplo de 1, 12 de 2, 123 de 3 y 1236 de 4. 9872, 
pues 9 es múltiplo de 1, 98 de 2, 987 de 3 y 9872 de 4.*/


int Soluciones[100]= {0};
int IndexSoluciones = 0;
bool NumerosUsados[9] = {0};
// Numero de cifras, cifra actual, 

void ObtenerNumeros(int m_CantCifras, int n_CantActual, int NumeroActual){
    if( n_CantActual > m_CantCifras){
        Soluciones[IndexSoluciones] = NumeroActual;
        IndexSoluciones++;   
        return;
    }

    for(int i_Numero = 1; i_Numero <= 9; i_Numero++){        
        if(NumerosUsados[i_Numero - 1]) continue; //No repetir un mismo numero

        int NuevoNumero = i_Numero + NumeroActual * 10;
        if(NuevoNumero % n_CantActual == 0){//Poda
            NumerosUsados[i_Numero - 1] = true; //Marcamos
            ObtenerNumeros(m_CantCifras, n_CantActual + 1, NuevoNumero); //Exploro, paso recursivo
            NumerosUsados[i_Numero - 1] = false; //Desmarcamos  
        } 
    }

}


int main(){
    int m; 
    cout<<"Ingrese su cantidad de cifras (m): ";// cin>>m;
    if( 0 > m || m > 9){
        cout<<"Bro"<<endl;
    }
    m=10;
    ObtenerNumeros(m, 1, 0);
    
    for(int i=0; i < IndexSoluciones; i++){
        cout<<"SOLUCION #"<<i+1<<": "<<Soluciones[i]<<endl;
    }
    if(Soluciones[0] == 0 ) cout<<"No se hayaron soluciones para "<<m<<" cantidad de cifras (m)"<<endl;

    return 0;
}