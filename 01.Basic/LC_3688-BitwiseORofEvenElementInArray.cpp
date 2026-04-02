// TC : O(N) , SC : O(1)
class Solution {
public:
    int evenNumberBitwiseORs(vector<int>& nums) {
        int bitOr = 0 ;
        for( int num : nums )
            if( !(num & 1) )
                bitOr |= num ;
        return bitOr ;
    }
};