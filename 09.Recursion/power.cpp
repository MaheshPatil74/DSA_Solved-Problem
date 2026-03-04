#include<iostream>
using namespace std ;

int power(int base , int n ){
    if(n==0)
        return 1 ;

    return base * power(base,n-1) ;
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