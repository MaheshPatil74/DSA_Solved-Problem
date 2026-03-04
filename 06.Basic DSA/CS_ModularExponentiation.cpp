/*
Modular Arithmetics : 
Properties : 
a%m + b%m = (a+b)%m 
a%m - b%m = (a-b)%m 
a%m * b%m = (a*b)%m
a%m / b%m = (a/b)%m  
(((a%m)%m).....)%m = a%m 
*/

int modularExponentiation(int x , int n , int m ){
    int res = 1 ;
    while(n>0){
        if(n&1){
            // n is Odd
            res = ( 1LL * res * (x%m) )%m ;
        }
        x = ( 1LL * (x%m) * (x%m) )%m ;
        n = n>>1 ;
    }
    return res ;
}