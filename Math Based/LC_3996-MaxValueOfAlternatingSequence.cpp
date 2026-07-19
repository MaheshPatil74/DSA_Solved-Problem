// TC : O(1) , SC : O(1)
class Solution {
public:
    long long maximumValue(int n, int s, int m) {
        long long ans1 = 1LL * s + 1LL * ((n - 1) / 2) * (m - 1);

        long long ans2 = s;
        if (n >= 2) 
            ans2 = 1LL * s + m + 1LL * ((n - 2) / 2) * (m - 1);

        return max(ans1, ans2);
    }
};