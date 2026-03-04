class Solution {
private :
    // Approach 1 :
    // Using Normal Approach but TLE Happens
    int solve1(vector<int>& cost , int n ){
        // BASE CASE
        if( n == 0 )
            return cost[0] ;
        if( n == 1 )
            return cost[1] ;

        int ans = cost[n] + min( solve1(cost,n-1) , solve1(cost,n-2)) ;
        return ans ;
    }

        // Approach 2 : DP Approach : Top-Down Approach ==>>
        // TC : O(n)  and SC = O(n)+O(n)
        // Using Recursion and Memoization
    int solve2(vector<int>& cost , int n , vector<int>& dp ){
        // BASE CASE
        if( n == 0 )
            return cost[0] ;
        if( n == 1 )
            return cost[1] ;

        // step 3
        if( dp[n] != -1 )
            return dp[n] ;

        // step 2
        dp[n] = cost[n] + min( solve2(cost,n-1 , dp) , solve2(cost,n-2,dp)) ;
        return dp[n] ;
    }

    // Approach 3 : DP Approach : Bottom-Up Approach ==>>
    // TC : O(n) and SC = o(n)
    // using Tabulation
    int solve3(vector<int>& cost , int n ){
        // step 1 : Creation of DP Array
        vector<int> dp(n+1) ;

        // step 2 : Base case analyze
        dp[0] = cost[0] ;
        dp[1] = cost[1] ;

        // step 3
        for( int i = 2 ; i<n ; i++ ){
            dp[i] = cost[i] + min(dp[i-1],dp[i-2]) ;
        }
        return min(dp[n-1],dp[n-2]) ;
    }

    // Approach 4 : Space Optimisation Approach : 
    // TC : O(n) and SC = O(1)
    // using BrainStorming : Space Optimisation
    int solve4(vector<int>& cost , int n ){
        
        int prev2 = cost[0] ;
        int prev1 = cost[1] ;

        // step 3
        for( int i = 2 ; i<n ; i++ ){
            int curr = cost[i] + min( prev1 , prev2 ) ;
            prev2 = prev1 ;
            prev1 = curr ;
        }
        return min( prev1 , prev2 ) ;
    }

public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size() ;

        // // For Solve1 Func : 
        // // below line can be simplified more==>> HOMEWORK
        // int ans = min( solve1(cost,n-1) , solve1(cost,n-2)) ;
        // return ans ;

        // // For Solve2 Func : 
        // // step 1
        // vector<int> dp(n+1 , -1) ;
        // int ans = min( solve2(cost,n-1,dp) , solve2(cost,n-2,dp)) ;
        // return ans ;

        // // For Solve3 Func : 
        // return solve3(cost,n) ;

        // For Solve4 Func : 
        return solve4(cost,n) ;
    }
};