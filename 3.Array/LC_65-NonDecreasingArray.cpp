class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int cnt = 0;

        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] < nums[i - 1]) {
                cnt++;
                if (cnt > 1) 
                    return false;

                // decide which element to modify
                if (i - 2 < 0 || nums[i] >= nums[i - 2]) {
                    // peeche wala fix
                    nums[i - 1] = nums[i]; 
                } 
                else {
                    // aage wala fix
                    nums[i] = nums[i - 1]; 
                }
            }
        }
        return true;
    }
};