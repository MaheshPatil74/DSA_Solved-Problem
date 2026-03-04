#include <iostream>
#include<math.h>
using namespace std ;

//Problem : "Binary to Decimal"
int BinaryToDecimal1( int n ){
    int ans = 0 ;
    int place = 1 ;
    while( n!= 0 ){
        int digit = n%10 ;
        if( digit == 1 ){
            ans = (digit * place ) + ans ;
        }
        place *= 2 ;
        n = n / 10 ;
    }
    return ans ;
}

int BinaryToDecimal2( int n ){
    int ans = 0 ;
    int place = 1 ;
    while( n!= 0 ){
        int digit = n&1 ;
        if( digit == 1 ){
            ans = ( place ) + ans ;
        }
        place *= 2 ;
        n = n >> 1 ;
    }
    return ans ;
}

int main() {
    
    int num ;
    cout<<"Enter The Number : ";
    cin>>num ;
    cout<<"Answer : "<<BinaryToDecimal1(num)<<endl ;
    cout<<"Answer : "<<BinaryToDecimal2(num)<<endl ;
    
    return 0; 
}