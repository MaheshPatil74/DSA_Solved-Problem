// TC : O(1) , SC : O(1)
class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        if (nums.size() < 3)
            return -1;

        int a = nums[0], b = nums[1], c = nums[2];

        // find middle of 3 numbers
        if ((a > b && a < c) || (a < b && a > c)) return a;
        if ((b > a && b < c) || (b < a && b > c)) return b;
        return c;
    }
};