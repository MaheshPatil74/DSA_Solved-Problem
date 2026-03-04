#include <iostream>
using namespace std ;

//Problem : "No. of 1 or set Bits : "
int NoOfOneBit( int n ){
    int count = 0 ;

    while( n!=0 ){
        
        if( n&1 ){
            count++ ;
        }
        n = n>>1 ;
    }
    return count ;
}

int main() {
    
    int num ;
    cout<<"Enter The Number : ";
    cin>>num ;
    
    cout<<"No. of 1 Bits : "<<NoOfOneBit(num) ;
    
    return 0; 
}