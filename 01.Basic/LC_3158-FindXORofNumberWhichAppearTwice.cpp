// Approach 1 : 
// TC : O(N) , SC : O(51)==O(1)
class Solution {
public:
    int duplicateNumbersXOR(vector<int>& nums) {
        vector<bool> present(51,false) ;
        int res = 0 ;
        for( int num : nums ){
            if( present[num] )
                res ^= num ;
            else
                present[num] = true ;
        }
        return res ;
    }
};