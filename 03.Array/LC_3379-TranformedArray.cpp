// Approach 2 : Same as 1 But only one condition
// TC : O(N) , SC : O(N)
class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> res(n) ;

        for( int i = 0 ; i<n ; i++ ){
            int idx = ((i + nums[i]) % n + n) % n; ;
            res[i] = nums[idx] ;
        }
        return res ;
    }
};

// Approach 1 : Brute Force
// TC : O(N) , SC : O(N)
class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> res(n) ;

        for( int i = 0 ; i<n ; i++ ){
            int idx = i ;
            if( nums[i] == 0 )
                idx = i ;
            else if( nums[i] > 0 )
                idx = ( i + nums[i] ) % n ;
            else
                idx = ((i + nums[i]) % n + n) % n;

            res[i] = nums[idx] ;
        }
        return res ;
    }
};