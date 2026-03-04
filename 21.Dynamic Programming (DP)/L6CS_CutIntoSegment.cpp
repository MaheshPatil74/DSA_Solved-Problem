#include<limits.h>

// Approach 1 :
// Using Normal only recursion Approach but TLE Happens
int solve1(int n, int x, int y, int z){
    // base case
    if( n==0 )
        return 0 ;

    if( n<0 )
        return INT_MIN ;

    int a = solve1(n-x,x,y,z) + 1 ;
    int b = solve1(n-y,x,y,z) + 1 ;
    int c = solve1(n-z,x,y,z) + 1 ;

    int ans = max( a , max(b,c)) ;
    return ans ;
}

// Approach 2 : DP Approach : Top-Down Approach ==>>
// TC : O(n)  and SC = O(n)+O(n)
// Using Recursion and Memoization
int solve2(int n, int x, int y, int z , vector<int> dp ){
    // base case
    if( n==0 )
        return 0 ;

    if( n<0 )
        return INT_MIN ;

    if( dp[n] != -1 )
        return dp[n] ;

    int a = solve2(n-x,x,y,z,dp) + 1 ;
    int b = solve2(n-y,x,y,z,dp) + 1 ;
    int c = solve2(n-z,x,y,z,dp) + 1 ;

    dp[n] = max( a , max(b,c)) ;
    return dp[n] ;
}

// Approach 3 : DP Approach : Bottom-Up Approach ==>>
// TC : O(n) and SC = o(n)
// using Tabulation
int solve3(int n, int x, int y, int z  ){
    
    vector<int> dp(n+1 , INT_MIN) ;
    dp[0] = 0 ;

    for(int i = 1 ; i<=n ; i++){
        if( i-x >= 0 && dp[i-x] != -1 )
            dp[i] = max( dp[i] , dp[i-x] + 1 ) ;

        if( i-y >= 0 && dp[i-y] != -1 )
            dp[i] = max( dp[i] , dp[i-y] + 1 ) ;

        if( i-z >= 0 && && dp[i-x] != -1 )
            dp[i] = max( dp[i] , dp[i-z] + 1 ) ;
    } 

    if( dp[n]<0 )
        return 0 ;
    else
        return dp[n] ;
}

int cutSegments(int n, int x, int y, int z) {
	// Write your code here.

    // // Approach 1 
    // int ans = solve1(n,x,y,z) ;
    // if( ans<0 )
    //     return 0 ;
    // else
    //     return ans ;

    // // Approach 2
    // vector<int> dp(n+1 , -1) ;
    // int ans = solve2(n,x,y,z,dp) ;
    // if( ans<0 )
    //     return 0 ;
    // else
    //     return ans ;
        
    // Approach 3
    return solve3(n,x,y,z) ;

}