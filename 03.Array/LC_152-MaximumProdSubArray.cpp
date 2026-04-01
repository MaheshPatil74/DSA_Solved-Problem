// Approach 1 : brute force ==>> TLE occur
// TC : O(N*N) , SC : O(1)



// Approach 1 : brute force ==>> TLE occur
// TC : O(N*N) , SC : O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = INT_MIN ;
        for( int i = 0 ; i<nums.size() ; i++ ){
            int prod = 1 ;
            for( int j = i ; j<nums.size() ; j++ ){
                prod *= nums[j] ;
                ans = max( ans , prod ) ;
            }
        }
        return ans ;
    }
};