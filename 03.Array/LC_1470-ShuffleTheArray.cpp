

// approach 1 : Using Extra Array
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
        int i = 0 ;
        int j = n ;
        vector<int> ans;
        while( i<n ){
            ans.push_back( nums[i] );
            ans.push_back( nums[j] );
            i++ ;
            j++ ;
        }
        return ans ;
    }
};