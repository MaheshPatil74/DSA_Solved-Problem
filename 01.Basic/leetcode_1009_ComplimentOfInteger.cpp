/*
// Leetcode solved
class Solution {
public:
    int bitwiseComplement(int n) {
        if(n == 0) return 1;
        
        int mask = 0;
        int temp = n;
        
        while(temp){
            mask = (mask << 1) | 1;
            temp >>= 1;
        }
        
        return mask ^ n;
    }
};
*/

#include <iostream>
#include<math.h>
using namespace std ;

//Problem : "Compliment of Integer"
int Compliment( int n ){
    
    int m = n ;
    int mask = 0 ;
    //edge case
    if(n==0){
        return 1 ;
    }
    while(m!=0){
        mask = (mask<<1) | 1 ;
        m = m>>1 ;
    }
    int ans = (~n) & mask ;
    return ans ;
}
int main() {
    int num ;
    cout<<"Enter The Number : ";
    cin>>num ;
    cout<<"Compliment of Integer : "<<Compliment(num) ;
    
    return 0; 
}