// TC : O(N) , SC : O(1)
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int minOp = 0 ;
        for( int num : nums )
            if( num%3 )
                minOp++ ;
        return minOp ;
    }
};