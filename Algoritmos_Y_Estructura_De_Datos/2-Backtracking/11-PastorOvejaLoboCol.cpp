#include<iostream>
#include<string>
using namespace std;

class SerVivo{
    public:
    string Nombre;
    int Id;
    SerVivo(): Nombre(" "), Id(-1){};
    SerVivo(string _Nombre, int _Id): Nombre(_Nombre), Id(_Id){};
    void PuedeEstar(SerVivo Primero, SerVivo Segundo){
        if(Primero.Id < Segundo.Id){
            cout<<Segundo.Nombre<<" se comio a "<<Primero.Nombre<<endl;
        }
    }
};

void MoverA(SerVivo *a, SerVivo *b, SerVivo *c, SerVivo *d){
    SerVivo aux1 = *a;
    SerVivo aux2 = *b;

    *a= *c;
    *b = *d;
    *c= aux1;
    *d = aux2;
}

    void MoverA(bool *a, bool *b, bool *c, bool *d){
        bool aux1 = *a;
        bool aux2 = *b;

        *a= *c;
        *b = *d;
        *c= aux1;
        *d = aux2;
    }

bool EstadoValido(SerVivo Orilla1[], SerVivo Orilla2[]){
    bool HayPastor1=false, HayCol1=false, HayOveja1=false, HayLobo1=false;
    bool HayPastor2=false, HayCol2=false, HayOveja2=false, HayLobo2=false;
    for(int i=0; i<4; ++i){
        if(Orilla1[i].Id==0) HayPastor1=true;
        else if(Orilla1[i].Id==1) HayCol1=true; 
        else if(Orilla1[i].Id==2) HayOveja1=true; 
        else if(Orilla1[i].Id==3) HayLobo1=true; 
    }
    
    if(!HayPastor1&&HayOveja1&&HayLobo1){ //si el pastor no esta y esta el lobo y la oveja estado invalido
        return false;
    }
    if(!HayPastor1&&HayOveja1&&HayCol1){ //si el pastor no esta y esta la oveja con la col estado invalido
        return false;
    }
    bool Orilla11=true;//Si llegamos aqui significa que el lado 1 es valido
        for(int i=0; i<4; ++i){
        if(Orilla2[i].Id==0) HayPastor2=true;
        else if(Orilla2[i].Id==1) HayCol2=true; 
        else if(Orilla2[i].Id==2) HayOveja2=true; 
        else if(Orilla2[i].Id==3) HayLobo2=true; 
    }
        if(!HayPastor2&&HayOveja2&&HayLobo2){ //si el pastor no esta y esta el lobo y la oveja estado invalido
        return false;
    }
    if(!HayPastor2&&HayOveja2&&HayCol2){ //si el pastor no esta y esta la oveja con la col estado invalido
        return false;
    }
    bool Orilla22=true;// el otro es valido
    return Orilla11&&Orilla22;
}
void LaCanoa2(SerVivo LadoIzquierdo[], SerVivo LadoDerecho[], SerVivo Rio[], int IndexACompañante, int SumaId=0){
    SumaId=0;
    for(int i=0; i<4; i++) SumaId+=LadoDerecho[i].Id;
    if(SumaId==6){
        return;
    }

    for(int i=IndexACompañante; i<4; ++i){
        MoverA(&LadoIzquierdo[0], &LadoIzquierdo[i], &Rio[0], &Rio[1]); 
        if(EstadoValido(LadoIzquierdo, LadoDerecho)){ //La primera iteracio falla y solo entra cuando mueva la oveja
                LaCanoa2(LadoIzquierdo, LadoDerecho, Rio,i, SumaId);
            MoverA(&Rio[0], &Rio[1], &LadoDerecho[0],&LadoDerecho[i]);
            if(EstadoValido(LadoIzquierdo, LadoDerecho)){
            MoverA(&LadoDerecho[0],&LadoDerecho[i], &Rio[0], &Rio[1]);

        MoverA(&LadoIzquierdo[0], &LadoIzquierdo[i], &Rio[0], &Rio[1]);     

            }
            
    }
    }




    LaCanoa2(LadoIzquierdo, LadoDerecho, Rio,IndexACompañante, SumaId);

return;
}


int main(){
    //se declara un arreglo que almacena los cosos que estan en un lado de la orilla del rio
    SerVivo OrillaIzquierda[4] ={SerVivo("Pastor", 0), SerVivo("Col", 1), SerVivo("Oveja", 2), SerVivo("Lobo", 3)}; //Bueno la col no es un ser vivo pero se entiende el beta mano
    SerVivo Río[2] = {SerVivo()};
    SerVivo OrillaDerecha[4] = {SerVivo()};
    int IdTotal=0;
    for(int i=0; i<4; i++){
        IdTotal+=OrillaIzquierda[i].Id;
    }

    LaCanoa2(OrillaIzquierda, Río, OrillaDerecha, 0);

    return 0;
}