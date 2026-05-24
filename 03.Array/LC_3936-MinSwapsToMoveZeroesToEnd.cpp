// TC : O(N) , SC : O(1)
class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int swaps = 0 ;
        int left = 0 , right = nums.size()-1 ;

        while( left < right ){
            while( left < nums.size() && nums[left] != 0 )
                left++ ;

            while( right >= 0 && nums[right] == 0 )
                right-- ;

            if( left < right ){
                swaps++ ;
                swap( nums[left++] , nums[right--] );
            }
        }
        return swaps ;
    }
};