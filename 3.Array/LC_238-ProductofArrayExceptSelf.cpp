// Approach 3 : optimisation in approach 2 
// TC : N
// SC = 1 
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size() ;

        vector<int> ans(n,1) ;
        for( int i = 1 ; i<n ; i++ )
            ans[i] = ans[i-1] * nums[i-1] ;

        int suffix = 1 ;
        for( int i = n-2 ; i>=0 ; i-- ){
            suffix = suffix * nums[i+1] ;
            ans[i] = ans[i] * suffix ; 
        }

        return ans ;
    }
};

// Approach 2 : prefix and suffix array product
// TC : N
// SC = 3*N == N
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size() ;

        // Array to store prefixproduct of each 
        vector<int> prefix(n,1);
        for( int i = 1 ; i<n ; i++ )
            prefix[i] = prefix[i-1] * nums[i-1] ;

        // Array to store suffixproduct of each 
        vector<int> suffix(n,1);
        for( int i = n-2 ; i>=0 ; i-- )
            suffix[i] = suffix[i+1] * nums[i+1] ;

        // Final array 
        vector<int> ans(n,1) ;
        for( int i = 0 ; i<n ; i++ )
            ans[i] = prefix[i] * suffix[i] ;

        return ans ;
    }
};


// Approach 1 : Brute Force
// TC : N*N
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> ans(n) ;

        for( int i = 0 ; i<n ; i++ ){
            int product = 1 ;
            for( int j = 0 ; j<n ; j++ ){
                if ( i == j )
                    continue ;
                product *= nums[j] ;
                if( product == 0 )
                    break ;
            }
            ans[i] = product ;
        }
        return ans ;
    }
};