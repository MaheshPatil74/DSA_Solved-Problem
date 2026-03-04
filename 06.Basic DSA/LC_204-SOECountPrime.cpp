#include<iostream>
#include<vector>
using namespace std ;

//using --> Sieve Of EratoSthenes Method :  

int CountPrime(int n ){
    int count = 0 ;
    vector<bool> prime(n+1,true ) ;

    prime[0] = prime[1] = false ;

    for(int i = 2 ; i<n ; i++ ){

        if( prime[i] ){
            count++ ;
            for(int j = 2*i ; j<n ; j=j+i ){
                prime[j] = 0 ;
            }
        }
    }
    return count ;
}




/*
//my Approach : 
// But Using These Approach tiem Complexity Is O(n*n) : 
//hence Time Limit exceeded (TLE) : 

bool isPrime(int p ){
    for(int i=2 ; i<p ; i++ ){
        if( p%i == 0 ){
            return false ;
        }
    }
    return true ;
}

int CountPrime( int n ){
    int count = 0 ;
    for(int i = 2 ; i<=n ; i++ ){
        if( isPrime(i) ){
            count++ ;
        }
    }
    return count ;
}
*/

int main(){
    int num ;
    cout<<"Enter The Number : ";
    cin>>num ;

    int ans = CountPrime(num) ; 
    cout<<ans ;
    return 0 ;
}
