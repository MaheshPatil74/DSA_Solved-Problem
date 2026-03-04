#include <iostream>
#include<math.h>
using namespace std ;

//Problem : "Binary to Decimal"
int BinaryToDecimal( int n ){
    int ans = 0 , i = 0 ;
    
    while( n!=0 ){
        int digit = n%10 ;
        if( digit == 1 ){
            ans = ans + pow(2,i) ;
        }
        n = n/10 ;
        i++ ;
    }
    return ans ;
}
int main() {
    
    int num ;
    cout<<"Enter The Number : ";
    cin>>num ;
    cout<<"Answer : "<<BinaryToDecimal(num) ;
    
    return 0; 
}