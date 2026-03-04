#include<iostream>
using namespace std ;

int SetBit(int n){
    
    int count = 0 ;

    while(n!=0){
        if(n&1){
            count++ ;
        }
        n = n>>1 ; 
    }

    return count ;
}

int main(){
    int num1 , num2 ; 
    cout<<"Enter The First Number : ";
    cin>>num1 ;
    cout<<"Enter The Second Number : ";
    cin>>num2 ;

    cout<<"Set Bit in "<<num1<<" is : "<<SetBit(num1)<<endl ;
    cout<<"Set Bit in "<<num2<<" is : "<<SetBit(num2)<<endl ;
    cout<<"Total Number of Set Bit in Both "<<num1<<" & "<<num2<<" is : "<<SetBit(num1)+SetBit(num2)<<endl ;
}