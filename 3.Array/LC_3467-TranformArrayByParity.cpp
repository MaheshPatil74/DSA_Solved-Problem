// Approach 1 : Two Pass : Counting Number of even and odd then replace
// TC : O(N)
class Solution {
public:
    vector<int> transformArray(vector<int>& nums) {
        int n = nums.size() ;
        int even = 0 ;
        for( int i = 0 ; i<n ; i++ )
            if( nums[i]%2 == 0 )
                even++ ;

        for( int i = 0 ; i<n ; i++ )
            nums[i] = (i<even) ? 0 : 1 ;

        return nums ;
    }
};