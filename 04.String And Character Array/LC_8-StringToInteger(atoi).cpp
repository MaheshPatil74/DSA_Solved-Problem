// Approach: Simulation
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();

        // 1. skip spaces
        while (i < n && s[i] == ' ')
            i++;

        // 2. sign
        bool positive = true;
        if (i < n && (s[i] == '+' || s[i] == '-')) {
            if (s[i] == '-')
                positive = false;
            i++;
        }

        // 3. skip leading zeros
        while (i < n && s[i] == '0')
            i++;

        // 4. digits
        long long ans = 0;
        while (i < n && s[i] >= '0' && s[i] <= '9') {
            ans = ans * 10 + (s[i] - '0');
            if (ans > INT_MAX)
                break;
            i++;
        }

        // 5. apply sign
        if (!positive)
            ans = -ans;

        // 6. clamp
        if (ans > INT_MAX) return INT_MAX;
        if (ans < INT_MIN) return INT_MIN;

        return ans;
    }
};