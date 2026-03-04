#include<bits/stdc++.h>
using namespace std;


// Approach 3 : Space Optimisation Approach : 
// TC : O(n) and SC = O(1)
int main()
{
        int n ;
        cin>> n ;

        int prev2 = 0 ; 
        int prev1 = 1 ;

        if( n == 0 )
            return prev2 ;

        for(int i = 2 ; i<=n ; i++ ){
                int next = prev1 + prev2 ;
                prev2 = prev1 ;
                prev1 = next ;
        }

    cout<< prev1 <<endl ;
    return 0 ;
}



/*
// Approach 2 : DP Approach : Bottom-Up Approach ==>>
// TC : O(n) and SC = o(n)
int fib( int n ){
    vector<int> dp(n+1) ;

    dp[0] = 0 ;
    dp[1] = 1 ;

    for( int i = 2 ; i<=n ; i++ ){
        dp[i] = dp[i-1] + dp[i-2] ;
    }
    return dp[n] ;
}

int main()
{
    int n ;
    cin>> n ;

    cout<< fib(n) <<endl ;
    return 0 ;        
}
*/



/*
// Approach 1 : DP Approach : Top-Down Approach ==>>
// TC : O(n)  and SC = O(n)+O(n)
int fib( int n , vector<int>& dp){
    // base case
    if( n <= 1 )
        return n ;

    // step 3
    if( dp[n] != -1 )
        return dp[n] ;

    // step 2
    dp[n] = fib(n-1 , dp) + fib(n-2 , dp) ;
    return dp[n] ;
}

int main()
{
    int n ;
    cin>> n ;

    // step 1
    vector<int> dp(n+1) ;
    for( int i = 0 ; i<=n ; i++ ){
        dp[i] = -1 ;
    }

    cout<< fib(n,dp) <<endl ;
    return 0 ;        
}
*/


/*
// Approach  : Normal Approach :
int main()
{
        int n ;
        cin>> n ;

        int a = 0 ; 
        int b = 1 ;

        int next = 0 ;
        for(int i = 1 ; i<n ; i++ ){
                next = a + b ;
                a = b ;
                b = next ;
        }

        if(n==1){
            cout<<b ;
        }
        else if(n==2){
            cout<<b ;
        }
        else{
            cout<<next ;
        }
}
*/