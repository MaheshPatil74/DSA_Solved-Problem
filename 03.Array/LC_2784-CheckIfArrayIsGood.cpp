// TC : O(N) , SC : O(N)
class Solution {
public:
    bool isGood(vector<int>& nums) {
        int n = nums.size();
        vector<int> cnt(n, 0);

        for (int x : nums) {
            if (x < 1 || x >= n) return false;
            cnt[x]++;
        }

        for (int i = 1; i < n - 1; i++) 
            if (cnt[i] != 1) 
                return false;

        return cnt[n - 1] == 2;
    }
};