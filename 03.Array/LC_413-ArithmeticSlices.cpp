// TC : O(N) , SC : O(1)
class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n = nums.size() ;

        if( n < 3 )
            return 0 ;

        int totalSlices = 0 , currentTotal = 0 ;

        for( int i = 2 ; i<n ; i++ ){
            
            if( nums[i]-nums[i-1] == nums[i-1] - nums[i-2] )
                currentTotal++ ;
            else
                currentTotal = 0 ;
                
            totalSlices += currentTotal ;
        }
        return totalSlices ;
    }
};