// TC : O(N) , SC : O(1)
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int reachIdx = 0 ;
        int n = nums.size() ;

        for( int i = 0 ; i<n ; i++ ){
            if( i>reachIdx )
                return false ;
            reachIdx = max( reachIdx , nums[i] + i );
            if( reachIdx >= n-1 )
                return true ;
        }
        return (reachIdx>=n-1) ;
    }
};