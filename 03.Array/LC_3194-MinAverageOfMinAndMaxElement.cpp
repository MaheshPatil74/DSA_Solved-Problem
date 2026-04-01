// TC : O(N) , SC : O(1)
class Solution {
public:
    double minimumAverage(vector<int>& nums) {
        double minElement = INT_MAX ;

        sort( nums.begin() , nums.end() );

        int firstIdx = 0 ; 
        int lastIdx = nums.size()-1 ;
        while( firstIdx < lastIdx ){
            double avg =  (double)( nums[firstIdx] + nums[lastIdx] ) / 2 ;
            minElement = min( minElement , avg ) ;
            firstIdx++ ;
            lastIdx-- ;
        }
        return minElement ;
    }
};