// Approach 1 : Two Pass and optimal
// TC : O(N) , SC : O(1)
class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        
        int middleIdx = -1 ;

        long long totalSum = 0 ;
        for( int num : nums )
            totalSum += num ;

        int leftSum = 0 ;
        int rightSum = totalSum ;

        for( int i = 0 ; i<nums.size() ; i++ ){
            rightSum -= nums[i] ;
            if( leftSum == rightSum )
                return i ;
            leftSum += nums[i] ;
        }
        return -1 ;
    }
};