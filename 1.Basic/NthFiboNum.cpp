#include<iostream>
using namespace std ;

int NthFiboNum(int n){
    int num1 = 0 ;
    int num2 = 1 ;
    int next ;
    
    if(n==1){
        return num1 ;
    }
    else if(n==2){
        return num2 ;
    }

    for(int i = 3 ; i<=n ; i++){
        next = num1 + num2 ;
        num1 = num2 ;
        num2 = next ;
    }
    return next ;
}

int main(){
    int num ; 
    cout<<"Enter The value of n for Nth Fibonacci Number : ";
    cin>>num ;

    cout<<num<<"th term in Fibonacci Series is : "<<NthFiboNum(num)<<endl ;
}