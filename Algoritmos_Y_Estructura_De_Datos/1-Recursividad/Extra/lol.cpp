#include<iostream>
#include<cmath>
using namespace std;

int main(){

    int num, n1, n2, n3, n4, n5, n6, numSubtract, numProduct, imparNum, parNum;
    cout<<"Ingrese un numero: "; cin>>num;

    if( num > 1 ){ // 2 digitos

        n1 = num/10;
        n2 = num%10;
        imparNum = n1;
        parNum = n2;
        if( n1 > n2 ){
            numSubtract = imparNum - parNum;
            cout<<numSubtract;
        }else{
            numProduct = imparNum * parNum;
            cout<<numProduct;
        }
    }else if( num > 2){

        n1 = num/100; // 3 digitos
        n2 = (num/10)%10;
        n3 = num%10;
        imparNum = n1 * 10 + n3 * 1;
        parNum = n2;
        if( n1 + n3 > n2){
            numSubtract = imparNum - parNum;
            cout<<numSubtract;
        }else{
            numProduct = imparNum * parNum;
            cout<<numProduct;
        }
    }else if( num > 3){ // 4 digitos

        n1 = num/1000;
        n2 = (num/100)%10;
        n3 = (num/10)%10;
        n4 = num %10;
        imparNum = n1 * 10 + n3 * 1;
        parNum = n2 * 10 + n4 * 1;

        if( n1 + n3 > n2 + n4){
            numSubtract = imparNum - parNum;
            cout<<numSubtract;
        }else{
            numProduct = imparNum * parNum;
            cout<<numProduct;
        }
    }else if(num > 4){ // 5 digitos

        n1 = num/10000;
        n2 = (num/1000)%10;
        n3 = (num/100)%10;
        n4 = (num/10)%10;
        n5 = num%10;
        imparNum = n1 * 100 + n3 * 10 + n5 * 1;
        parNum = n2 * 10 + n4 * 1;

        if( n1 + n3 + n5 > n2 + n4){
            numSubtract = imparNum - parNum;
            cout<<numSubtract;
        }else{
            numProduct = imparNum * parNum;
            cout<<numProduct;
        }
    }else    if( num > 5 ){
        
        n1 = num/100000;
        n2 = (num/10000)%10;
        n3 = (num/1000)%10;
        n4 = (num/100)%10;
        n5 = (num/10)%10;
        n6 = num%10;
        imparNum = n1 * 100 + n3 * 10 + n5 * 1;
        parNum = n2 * 100 + n4 * 10 + n6 * 1;

        if( n1 + n3 + n5 > n2 + n4 + n6){
            numSubtract = imparNum - parNum;
            cout<<numSubtract;
        }else{
            numProduct = imparNum * parNum;
                cout<<numProduct;
        }
    }
    return 0;
}