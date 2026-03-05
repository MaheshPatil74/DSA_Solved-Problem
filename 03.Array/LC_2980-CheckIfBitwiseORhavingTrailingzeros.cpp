// only possible when "x" or "y" dono even ho tabjhi (x|y) main trailing zero hoga
// TC : O(N) , SC : O(1)
class Solution {
public:
    bool hasTrailingZeros(vector<int>& nums) {
        int evenCount = 0 ;
        for( int temp : nums ){
            if( temp % 2 == 0 ){
                evenCount++ ;
                if( evenCount>1 )
                    return true ;
            }
        }
        return false ;
    }
};