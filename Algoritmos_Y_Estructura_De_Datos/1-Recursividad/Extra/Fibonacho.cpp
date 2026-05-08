#include<iostream>
#include<cmath>
using namespace std;


int Fibonacho(int n){
    if(n<2) return n;
    return (Fibonacho(n-1) + Fibonacho(n-2));
}


int main(){

cout<<Fibonacho(6)<<endl;

    return 0;
}