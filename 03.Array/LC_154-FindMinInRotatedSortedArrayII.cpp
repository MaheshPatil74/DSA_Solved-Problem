// 154. Find Minimum in Rotated Sorted Array II

// Approach 2 : Binary Search
// Time Complexity: O( Log n )
// Space Complexity: O(1)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0 , right = nums.size() - 1 ;

        while( left < right ){
            int mid = left + (right-left)/2 ;

            if( nums[mid] > nums[right] )
                left = mid+1 ;
            else if( nums[mid] < nums[right] )
                right = mid ;
            else
                right-- ;
        }
        return nums[left] ;
    }
};

// Approach 1 : Brute force
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size() ;
        if( nums[0] < nums[n-1])
            return nums[0] ;

        for( int i = 1 ; i<n ; i++ )
            if( nums[i-1] > nums[i] )
                return nums[i] ;

        return nums[0] ;
    }
};