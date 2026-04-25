// Approach : Optimal
// TC : O(d) , SC : O(1)
class Solution {
public:
    bool validDigit(int n, int x) {
        int temp = n;
        bool found = false;

        // check all digits
        while (temp > 0) {
            int digit = temp % 10;
            if (digit == x) found = true;
            temp /= 10;
        }

        // find first digit
        while (n >= 10) {
            n /= 10;
        }

        // first digit should not be x
        if (n == x) return false;

        return found;
    }
};