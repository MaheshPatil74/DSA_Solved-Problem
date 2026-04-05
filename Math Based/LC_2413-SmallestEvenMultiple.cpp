// TC : O(1) , SC : O(1)
class Solution {
public:
    int smallestEvenMultiple(int n) {
        return ( n&1 ) ? n*2 : n ;
    }
};