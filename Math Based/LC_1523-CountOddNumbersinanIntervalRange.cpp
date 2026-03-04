// TC: O(1)
class Solution {
public:
    int countOdds(int low, int high) {
        int highOdd = (high + 1)/2 ;
        int lowOdd = low/2 ;
        return highOdd - lowOdd ;
    }
};