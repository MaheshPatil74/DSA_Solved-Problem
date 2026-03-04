// Time  : O(n)
// Space : O(1)

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        
        // Step 1 : Aplpply Operation
        for( int i = 0 ; i<nums.size()-1 ; i++ )
            if( nums[i] == nums[i+1] ){
                nums[i] = 2* nums[i] ;
                nums[i+1] = 0 ;
            }

        // Step 2 : Move zeroes To End
        int j = 0 ;
        for( int i = 0 ; i<nums.size() ; i++ ){
            if( nums[i] != 0 ){
                swap( nums[i] , nums[j] );
                j++ ;
            }
        }
        return nums;
    }
};