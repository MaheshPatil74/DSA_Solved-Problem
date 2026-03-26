// Approach 2 : Optimal Method – Right Shift Trick We shift both numbers right until they become equal.
// TC : O(LogN) , SC : O(1)
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int shift = 0;
        while(left != right) {
            left >>= 1;
            right >>= 1;
            shift++;
        }
        return left << shift;
    }
};



// Approach 1 : Causes TLE Problem
// TC : O(N) , SC : O(1)
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) {
        int bitAnd = left ;
        for( int i = left+1 ; i<=right ; i++ )
            bitAnd = bitAnd & i ;
        return bitAnd ;
    }
};