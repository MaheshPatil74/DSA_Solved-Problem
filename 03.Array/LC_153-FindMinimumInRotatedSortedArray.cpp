// 153. Find Minimum in Rotated Sorted Array
// Time Complexity: O(log n)
// Space Complexity: O(1)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0 ;
        int right = nums.size() - 1 ;

        if( nums[left] <= nums[right] )
            return nums[left] ;

        while( left < right ){
            int mid = left + (right-left)/2 ;
            if( nums[mid] >= nums[0] )
                left = mid+1 ;
            else
                right = mid ;
        }
        return nums[ left ];
    }
};