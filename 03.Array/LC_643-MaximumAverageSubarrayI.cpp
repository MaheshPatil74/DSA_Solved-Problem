// TC : O(N) , SC : O(1)
class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        double maxAvg = INT_MIN ;

        int i = 0 ;
        int j = 0 ;
        double sum = 0 ;
        while( j<nums.size() ){
            sum += nums[j] ;
            if( j-i+1 == k ){
                double avg = sum / k ;
                maxAvg = max( avg , maxAvg ) ;
                sum -= nums[i] ;
                i++ ;
            }
            j++ ;
        }
        return maxAvg ;
    }
};