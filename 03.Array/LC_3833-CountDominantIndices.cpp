// TC : O(N) 
class Solution {
public:
    int dominantIndices(vector<int>& nums) {
        int n = nums.size() ;
        int count = 0 ;
        int sum = nums[n-1] ;
        for( int i = n-2 ; i>=0 ; i-- ){
            int avg = sum / ( n-i-1) ;
            if( nums[i] > avg )
                count++ ;
            sum += nums[i] ;
        }
        return count ;
    }
};