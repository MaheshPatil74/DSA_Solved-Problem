#include<iostream>
using namespace std ;

int power(int a , int b ){

    //Base case
    if( b == 0 )
        return 1 ;

    if( b == 1 )
        return a ;

    // recursive call :
    int ans = power(a , b/2 ) ;

    if( b%2 == 0 )
        return ans * ans ;
    else
        return a * ans * ans ; 
}

int main(){
    int base,n ;
    cout<<"Enter The Base Value : ";
    cin>>base;
    cout<<"Enter The power of Base Value : ";
    cin>>n ;

    cout<<"Answer : "<<power(base,n)<<endl ;
    return 0 ;
}