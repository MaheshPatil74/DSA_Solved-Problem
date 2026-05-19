// TC : O(N) , SC : O(1)
class Solution {
public:
    int sumOfGoodNumbers(vector<int>& nums, int k) {
        long long sum = 0 ;
        int n = nums.size() ;

        for( int i = 0 ; i<n ; i++ ){
            bool good = true ;

            if( i-k>=0 && nums[i-k]>=nums[i] )
                good = false ;

            if( i+k<n && nums[i+k]>=nums[i] )
                good = false ;

            if( good )
                sum += nums[i] ;
        }
        return sum ;
    }
};