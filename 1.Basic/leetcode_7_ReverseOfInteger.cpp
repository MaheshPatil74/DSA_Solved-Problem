#include <iostream>
#include<math.h>
using namespace std ;

//Problem : "Reverse of Integer"
int Reverse( int n ){
    int ans = 0 ;
    
    while( n!=0 ){
        int digit = n%10 ;

        if( ( ans> INT_MAX/10 ) || ( ans< INT_MIN/10 ) ){
            return 0 ;
        }
        ans = ( ans * 10 ) + digit ;
        
        n /= 10 ;
    }
    return ans ;
}
int main() {
    
    int num ;
    cout<<"Enter The Number : ";
    cin>>num ;
    cout<<"Reverse of Integer : "<<Reverse(num) ;
    
    return 0; 
}