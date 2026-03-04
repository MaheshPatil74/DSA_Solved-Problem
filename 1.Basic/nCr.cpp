#include<iostream>
using namespace std ;

int factorial(int n){
    int ans = 1 ;
    for(int i = 1 ; i<=n ; i++){
        ans = ans * i ;
    }
    return ans ;
}


int nCr(int n , int r){
    int ans ;

    int = factorial(n) / ( factorial(r) * factorial(n-r) ) ;

    return ans ; 
}

int main(){
    int num1 , num2 ;
    cout<<"Enter N : ";
    cin>>num1 ;
    cout<<"Enter R : ";
    cin>>num2 ;

    cout<<"nCr : "<<nCr(num1 , num2)<<endl;
    return 0 ;
}