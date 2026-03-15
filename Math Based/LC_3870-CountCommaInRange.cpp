// TC : O(1) , SC : O(1)
class Solution {
public:
    int countCommas(int n) {
        return (n<1000) ? 0 : n-999 ;
    }
};