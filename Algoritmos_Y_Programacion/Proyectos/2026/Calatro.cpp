#include<iostream>
#include<math.h>
using namespace std;


    char A1,A2,A3,A4,A5;
    int ValorCarta1,ValorCarta2,ValorCarta3,ValorCarta4,ValorCarta5;
    int PaloCarta1,PaloCarta2,PaloCarta3,PaloCarta4,PaloCarta5;
int Pica = 1;
int Corazon = 2;
int Trebol = 3;
int Diamante = 4;

int DevolverValorCarta(char Carta){
    switch (Carta)    {
    case 2: return 2;
    case 3: return 3;
    case 4: return 4;
    case 5: return 5;
    case 6: return 6;
    case 7: return 7;
    case 8: return 8;
    case 9: return 9;
    case 'T': return 10;
    case 'J': return 11;
    case 'Q': return 12;
    case 'K': return 13;
    case 'A': return 15; 
    default: return -676767;
    }
}
int DevolverPaloCarta(int Palo){
    switch (Palo){
    case 1:return Pica; 
    case 2:return Corazon; 
    case 3:return Trebol; 
    case 4:return Diamante; 
    default: return 0;
    }
}

void DevolverComodin(){

}

bool EsRoyalFlush();
bool EsStraightFlush();
bool EsFourOfAKind();
bool EsFullHouse();
bool EsFlush();
bool EsStraight();
bool EsThreeOfAKind();
bool EsTwoPair();
bool EsOnePair();
bool EsHighCard();

void BuscarMano( ){

}

int DevolverMayor(int a, int b){
    if( a > b){
        return a;
    }else{
        return b;
    }
}

void Intercambiar(int &a, int &b){
    a = a + b;
    b = a - b;
    a = a - b;
}
void OrdenarDescendente(){
    int Mayor = DevolverMayor(DevolverMayor(DevolverMayor(ValorCarta1,ValorCarta2),DevolverMayor(ValorCarta3,ValorCarta4)),ValorCarta5);
    
}

int main(){

    int Num;
    cin>>A1>>A2>>A3>>A4>>A5;
    cin>>Num;



    PaloCarta1 = Num / 10000; // el más a la izquierda
    PaloCarta2 = (Num / 1000) % 10;
    PaloCarta3 = (Num / 100) % 10;
    PaloCarta4 = (Num / 10) % 10;
    PaloCarta5 = Num % 10;
    int C1,C2,C3;
    cin>>C1>>C2>>C3;
    int B;
    cin>> B;
    ValorCarta1 = DevolverValorCarta(A1);
    ValorCarta2 = DevolverValorCarta(A2);
    ValorCarta3 = DevolverValorCarta(A3);
    ValorCarta4 = DevolverValorCarta(A4);
    ValorCarta5 = DevolverValorCarta(A5);

    int Total;

}


bool EsRoyalFlush();
bool EsStraightFlush();
bool EsFourOfAKind();
bool EsFullHouse();
bool EsFlush(){
    return (PaloCarta1 == PaloCarta2) && (PaloCarta1 == PaloCarta3) && (PaloCarta1 == PaloCarta4) && (PaloCarta1 == PaloCarta5);
}
bool EsStraight(){
    if(false){//comodin de mierda

    }else{
        return (ValorCarta2 == ValorCarta1 + 1) && (ValorCarta3 == ValorCarta2 + 1) && (ValorCarta4 == ValorCarta3 + 1) && (ValorCarta5 == ValorCarta4 + 1);
    }
}
bool EsThreeOfAKind();
bool EsTwoPair();
bool EsOnePair();
bool EsHighCard(){
    return !(EsRoyalFlush || EsStraightFlush || EsFourOfAKind || EsFullHouse || EsFlush || EsStraight || EsThreeOfAKind || EsTwoPair || EsOnePair);
}
