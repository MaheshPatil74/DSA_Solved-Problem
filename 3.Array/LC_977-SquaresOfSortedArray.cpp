// Approach 2: Two Pointer Approach (Interview Oriented)
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> ans(n) ;
        
        int left = 0 ;
        int right = n-1 ;
        int index = n-1 ;

        while( left <= right ){
            if( abs(nums[left]) > abs(nums[right]) ){
                ans[index--] = nums[left] * nums[left] ;
                left++ ;
            }
            else{
                ans[index--] = nums[right] * nums[right] ;
                right-- ;
            }
        }
        return ans ;
    }
};



// Approach 1: first square of each element, then sort the array
// Time Complexity: O(n log n)
// Space Complexity: O(1)
class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        
        for( int i = 0 ; i<nums.size() ; i++ )
            nums[i] = nums[i] * nums[i] ;
        
        sort( nums.begin() , nums.end() );
        return nums;
    }
};