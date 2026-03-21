// Approach 1 : counting method with extra array
// TC : O(N) , SC : O(N)
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans(nums.size()) ;
        int less = 0 ;
        int equal = 0 ;
        for( int num : nums ){
            if( num == pivot )
                equal++ ;
            else if( num<pivot )
                less++ ;
        }

        int lessIdx = 0 ;
        int equalIdx = less ;
        int largeIdx = less+equal ;
        for( int i = 0 ; i<nums.size() ; i++ ){
            if( nums[i] < pivot )
                ans[lessIdx++] = nums[i] ;
            else if( nums[i] > pivot )
                ans[largeIdx++] = nums[i] ;
            else
                ans[equalIdx++] = nums[i] ;
        }
        return ans ;
    }
};