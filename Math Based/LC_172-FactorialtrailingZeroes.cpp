// Complexity
// Time: O(log₅ n)
// Space: O(1)
class Solution {
public:
    int trailingZeroes(int n) {
        int count = 0;
        while(n > 0){
            n /= 5;
            count += n;
        }
        return count;
    }
};


451
1962
1834
3852
347
1046
1608