// TC : O(N) , SC : O(101) == O(1)
class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        vector<int> ans;
        int cnt[101] = {0};

        for(int x : nums) {
            cnt[x]++;
            if(cnt[x] == 2)
                ans.push_back(x);
        }
        return ans;
    }
};