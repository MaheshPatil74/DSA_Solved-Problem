#include <bits/stdc++.h> 
// Approach 1 :
// Using Normal only recursion Approach but TLE Happens
int solve1(vector<int> &nums , int n ){
    // base case
    if( n<0 )
        return 0 ;

    if( n==0 )
        return nums[0] ;

    int incl = solve1( nums , n-2) + nums[n] ;
    int excl = solve1( nums , n-1) + 0 ;

    return max(incl , excl  ) ;
}


// Approach 2 : DP Approach : Top-Down Approach ==>>
// TC : O(n)  and SC = O(n)+O(n)
// Using Recursion and Memoization
int solve2(vector<int> &nums , int n ,vector<int>&dp ){
    // base case
    if( n<0 )
        return 0 ;

    if( n==0 )
        return nums[0] ;

    if( dp[n] != -1 )
        return dp[n] ;

    int incl = solve2( nums , n-2,dp) + nums[n] ;
    int excl = solve2( nums , n-1,dp) + 0 ;

    dp[n] = max(incl , excl) ;
    return dp[n] ;
}   

// Approach 3 : DP Approach : Bottom-Up Approach ==>>
// TC : O(n) and SC = o(n)
// using Tabulation

int solve3( vector<int>& nums){ 
    int n = nums.size() ;
    vector<int> dp(n , 0 ) ;

    dp[0] = nums[0] ;

    for( int i = 1 ; i<n ; i++ ){
        int incl = dp[i-2] + nums[i] ;
        int excl = dp[i-1] + 0 ;
        dp[i] = max(incl,excl) ;
    }
    return dp[n-1] ;
}

// Approach 4 : Space Optimisation Approach : 
    // TC : O(n) and SC = O(1)
    // using BrainStorming : Space Optimisation
int solve4( vector<int>& nums){ 
    int n = nums.size() ;

    int prev2 = 0 ;
    int prev1 = nums[0] ;

    for( int i = 1 ; i<n ; i++ ){
        int incl = prev2 + nums[i] ;
        int excl = prev1 + 0 ;
        
        int ans = max(incl,excl) ;
        prev2 = prev1 ;
        prev1 = ans ;
    }
    return prev1 ;
}

int maximumNonAdjacentSum(vector<int> &nums){
    // Write your code here.

    // Approach 1
    // int n = nums.size() ;
    // int ans = solve1(nums , n-1) ;
    // return ans ;

    // approach 2 
    // int n = nums.size() ;
    // vector<int> dp(n , -1 ); 
    // int ans = solve2(nums , n-1,dp) ;
    // return ans ;

    // approach 3
    // return solve3(nums) ;

    // approach 4
    return solve4(nums) ;
}