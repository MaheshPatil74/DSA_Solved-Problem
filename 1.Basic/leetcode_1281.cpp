#include <iostream>
using namespace std ;

Problem : 
int ProductSumSub( int n ){
    int sum = 0 , product = 1 ;
    while( n!= 0){
        int rem = n%10 ;
        sum = sum + rem ;
        product = product * rem ;
        n = n/10 ;
    }
    int sub = product - sum ;
    return sub ;
}

int main() {
    
    int num ;
    cout<<"Enter The Number : ";
    cin>>num ;
    
    cout<<"Substraction : "<<ProductSumSub(num) ;
    
    return 0;
}