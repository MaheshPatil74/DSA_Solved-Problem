// TC : O(N*LogN) , SC : O(1)
class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort( nums.begin() , nums.end() , greater<int>() ) ;
        long long totalSum = 0 ;

        for( int i = 0 ; i<k ; i++ ){
            if( mul > 0 )
                totalSum += (long long)(nums[i])*mul ;
            else
                totalSum += nums[i] ;

            mul-- ;
        }
        return totalSum ;
    }
};