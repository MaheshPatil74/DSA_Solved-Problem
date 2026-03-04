#include<iostream>
using namespace std ;

int main(){
    int n ;

    cout<<"Enter The Number : ";
    cin>>n ;

    int fib1 = 0 ;
    int fib2 = 1 ;
    cout<<fib1<<" "<<fib2<<" ";
    for(int i = 1 ; i<=n ; i++ ){
        int next = fib1 + fib2 ;
        cout<<next<<" ";
        fib1 = fib2 ;
        fib2 = next ;
    }
    return 0 ;
}