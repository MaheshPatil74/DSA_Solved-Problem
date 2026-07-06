// TC : O(N) , SC : O(1)
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size() , neg = 0 , zeroes = 0 ;
        for( int num : nums ){
            if( num >= 1 )
                break ;
            if( num < 0 )
                neg++ ;
            else if( num == 0 )
                zeroes++ ;
        }

        return max( neg , n-neg-zeroes ) ;
    }
};