#include <bits/stdc++.h> 

// Approach 1 : DP Approach : Top-Down Approach ==>>
// TC : O(x*n)  and SC = o(x) ==>> x = amount and n == no. of coin
// Using Recursion and Memoization
int solveRec(vector<int> &num, int x){
    // BASE CASE
    if( x == 0 )
        return 0 ;
    if( x<0 )
        return INT_MAX ;

    int mini = INT_MAX ;
    for( int i =0 ; i<num.size() ; i++ ){
        int ans = solveRec( num , x-num[i] );
        if( ans != INT_MAX )
            mini = min( mini , 1+ans );
    }
    return mini ;
}


int solveMem(vector<int> &num, int x , vector<int> &dp){
    // BASE CASE
    if( x == 0 )
        return 0 ;
    if( x<0 )
        return INT_MAX ;

    if( dp[x] != -1 )
        return dp[x] ;

    int mini = INT_MAX ;
    for( int i =0 ; i<num.size() ; i++ ){
        int ans = solveRec( num , x-num[i] );
        if( ans != INT_MAX )
            mini = min( mini , 1+ans );
    }

    dp[x] = mini ;

    return mini ;
}

// Approach 3 : DP Approach : Bottom-Up Approach ==>>
// TC : O(x*n)  and SC = o(x)
// using Tabulation
int solveTab(vector<int> &num, int x ){
    vector<int> dp( x+1 , INT_MAX );
    dp[0] = 0 ;

    for( int i=1 ; i<=x ; i++ ){
        // trying to solve for every amount figure from 1 to x
        for( int j = 0 ; j<num.size() ; j++ ){
            if( i-num[j]>=0 && dp[i-num[j]] != INT_MAX ){
                dp[i] = min( dp[i] , 1+ dp[i-num[j]]) ;
            }
        }
    }

    if( dp[x] == INT_MAX )
        return -1 ;

    return dp[x] ;
}

int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    // // Approach 1 : TLE happens
    // int ans = solveRec(num,x) ;
    // if( ans == INT_MAX )
    //     return -1 ;
    // return ans ;

    // // Approach 2 : TLE happens
    // vector<int> dp( x+1 , -1 );
    // int ans = solveMem(num,x,dp) ;
    // if( ans == INT_MAX )
    //     return -1 ;
    // return ans ;

    // Approach 3 : accepted here
    return solveTab(num,x) ;
}