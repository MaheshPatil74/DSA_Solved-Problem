// Approach : Optimal
// TC : O(N) , SC : O(N)
class Solution {
public:
    vector<int> findValidElements(vector<int>& nums) {
        int n = nums.size() ;
        if( n <= 2 )
            return nums ;
        vector<int> rightMaxi(n) ;

        rightMaxi[n-1] = 0 ;
        for( int i = n-2 ; i>=0 ; i-- )
            rightMaxi[i] = max( nums[i+1] , rightMaxi[i+1] ) ;

        vector<int> ans ;
        ans.push_back(nums[0]);
        int leftMax = nums[0] ;
        for( int i = 1 ; i<=n-2 ; i++ ){
            if( nums[i] > leftMax ){
                ans.push_back(nums[i]);
                leftMax = nums[i] ;
            }
            else if( nums[i] > rightMaxi[i] )
                ans.push_back(nums[i]);
        }
        ans.push_back(nums[n-1]);
        return ans ;
    }
};