// TC : O(N) , SC : O(1)
class Solution {
public:
    int minimumCost(vector<int>& nums, int k) {
        const long long MOD = 1e9 + 7;

        long long operations = 0;
        long long currRes = k;

        for (int num : nums) {
            if (currRes < num) {
                long long need = num - currRes;
                long long multiple = (need + k - 1) / k;

                operations += multiple;
                currRes += multiple * 1LL * k;
            }
            currRes -= num;
        }
        operations %= MOD;

        long long ans = (operations * (operations + 1)) / 2;
        ans %= MOD;

        return (int)ans;
    }
};