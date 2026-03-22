// Approach 1 : Optimal
// Time: O(N) , Space: O(1) 
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size() ;
        if( n<=2 )
            return n ;

        int idx = 2 ;
        for( int j = 2 ; j<n ; j++ )
            if( nums[j] != nums[idx-2] )
                nums[idx++] = nums[j] ;

        return idx ;
    }
};