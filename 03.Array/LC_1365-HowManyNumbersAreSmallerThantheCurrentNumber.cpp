// OPtimal Is Possible by prefix sum

// Time Complexity: O(N^2) , Space Complexity: O(1)
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int>ans(nums.size());
        
        for( int i =0 ; i<nums.size() ; i++ ){
            int count = 0 ;
            for( int j = 0 ; j<nums.size() ; j++ ){
                if ( j == i )   
                    continue ;
                if( nums[j] < nums[i] )
                    count++ ;
            }
            ans[i] = count;
        }
        return ans ;
    }
};