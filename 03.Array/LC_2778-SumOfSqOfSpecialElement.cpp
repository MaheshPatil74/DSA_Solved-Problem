// TC : O(N) , SC : O(1)
class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n = nums.size() ;
        long long sqSum = 0 ;
        for( int i = 0 ; i<n ; i++ )
            if( n%(i+1) == 0 )
                sqSum += (nums[i]*nums[i]) ;
        return sqSum ;
    }
};