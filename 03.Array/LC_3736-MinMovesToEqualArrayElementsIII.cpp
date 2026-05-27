// TC : O(N) , SC : O(1)
class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi = nums[0] ;

        for( int num : nums )
            maxi = max( maxi , num ) ;

        int moves = 0 ;
        for( int num : nums )
            moves += ( maxi - num ) ;
            
        return moves ;
    }
};