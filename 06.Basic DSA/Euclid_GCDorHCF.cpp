#include<iostream>
using namespace std ;

//Using --> Euclid Algorithm

// Implementation 1 : Normal ==> Not more efficient
// TC : O( max( a,b ) )     
int gcd1( int a , int b ){
    if(a==0)
        return b ;
    if (b==0)
        return a ;

    while(a!=b){
        if( a>b )
            a=a-b ;
        else if( b>a )
            b=b-a ;
    }
    return a ;
}

// Implementation 2 : Optimal ==> interview preffered
// TC : O( LogN )       // sabse fast
int gcd2(int a, int b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

// Implementation 3 : Recursive
// TC : O( LogN )      
int gcd3(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}


int main(){
    int a , b ;
    cout<<"Enter The Number a & b : ";
    cin>>a>>b ;
    int ans = gcd1(a,b) ;
    // int ans = gcd2(a,b) ;
    // int ans = gcd3(a,b) ;
    cout<<"GCD or HCF of "<<a<<" ans "<<b<<" is "<<ans <<endl ;
    return 0 ;
}