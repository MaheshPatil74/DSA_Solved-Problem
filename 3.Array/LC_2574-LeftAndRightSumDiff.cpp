// Approach 2 : Optimal space
// TC : O(N) , SC : O(1)
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int totalSum = 0 ;
        for( int temp : nums )
            totalSum += temp ;

        int leftSum = 0 ;
        for( int i = 0 ; i<nums.size() ; i++ ){
            int current = nums[i] ;
            int rightSum = totalSum - leftSum - current ;
            nums[i] = abs(leftSum - rightSum) ;
            leftSum += current ;
        }    
        return nums ;
    }
};


// Approach 1 : Using Extra array
// TC : O(N) , SC : O(N)
class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> preSum(n,0) ;
        for( int i = 1 ; i<n ; i++ )
            preSum[i] = preSum[i-1] + nums[i-1] ;

        vector<int> sufSum(n,0) ;
        for( int i = n-2 ; i>=0 ; i-- )
            sufSum[i] = sufSum[i+1] + nums[i+1] ;

        for( int i = 0 ; i<n ; i++ )
            nums[i] = abs(preSum[i] - sufSum[i] );

        return nums ;
    }
};