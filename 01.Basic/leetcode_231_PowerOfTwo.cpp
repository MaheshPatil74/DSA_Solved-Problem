#include <iostream>
#include<math.h>
using namespace std ;

//Problem : "Power Of Two"
bool PowerOfTwo1( int n ){
    for( int i = 0 ; i<31 ; i++ ){
        int ans = pow(2,i);
        if( n == ans ){
            return true ;
        }
    }
    return false ;
}

//Efficient
bool PowerOfTwo2( int n ){
    int ans = 1 ;
    for( int i = 0 ; i<31 ; i++ ){
        if( n == ans ){
            return true ;
        }
        if(ans<INT_MAX/2){
            ans = ans * 2 ; 
        }
    }
    return false ;
}

// Using Bit Manipulation Sabse Efficient

class Solution {
public:
    bool isPowerOfTwo3(int n) {
        
        if( n<=0 )
            return false ;

        int count = 0 ;
        while( n != 0 ){
            if( n&1 )
                count++ ;
            n = n>>1 ;
        }

        if( count == 1 ){
            return true ;
        }
        return false ;
    }
};

int main() {
    int num ;
    cout<<"Enter The Number : ";
    cin>>num ;
    cout<<"Power Of Two : "<<PowerOfTwo1(num) ;
    cout<<"Power Of Two : "<<PowerOfTwo2(num) ;
    return 0; 
}