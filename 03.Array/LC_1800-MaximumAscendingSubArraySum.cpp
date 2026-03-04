// Approach 2 : Single Pass
// Time Complexity: O(N)
// Space Complexity: O(1)
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int currSum = nums[0] ;
        int maxSum = nums[0] ;

        for( int i = 1 ; i<nums.size() ; i++ ){
            if( nums[i-1] < nums[i] )
                currSum += nums[i] ;
            else
                currSum = nums[i] ;
            maxSum = max( maxSum , currSum ) ;
        }
        return maxSum ;
    }
};


// Approach 1 : Two Pointers
// Time Complexity: O(N)
// Space Complexity: O(1)
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size() ;
        int i = 0 ;
        int j = 1 ;

        int sum = 0 ;
        int maxSum = 0 ;

        while( j<n ){
            sum = nums[i] ;
            while( j<n && nums[j-1] < nums[j] ){
                sum += nums[j] ;
                j++ ;
            }
            maxSum = max( sum , maxSum ) ;

            i = j ;
            j++ ;
        }
        return maxSum ;
    }
};