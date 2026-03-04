// Approach 2 : using Kadane Algo 
// Time Complexity : O(N)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN ;
        int currSum = 0 ;
        for( int i = 0 ; i<nums.size() ; i++ ){
            currSum += nums[i] ;
            maxSum = max( currSum , maxSum ) ;
            if( currSum < 0 )
                currSum = 0 ;
        }
        return maxSum ;
    }
};


// Approach 1 : Brute Force
// Time Complexity : O(N^2)
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int maxSum = INT_MIN ;
        for( int i = 0 ; i<nums.size() ; i++ ){
            int sum = 0 ;
            for( int j = i ; j<nums.size() ; j++ ){
                sum += nums[j] ;
                maxSum = max( sum , maxSum ) ;
            }
        }
        return maxSum ;
    }
};