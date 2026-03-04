// Sabse optimal : other ways are sorting and O(N*N)
// TC : O(N) , SC : O(1)
class Solution {
public:
    int maxProductDifference(vector<int>& nums) {
        int firstMax = INT_MIN, secondMax = INT_MIN;
        int firstMin = INT_MAX, secondMin = INT_MAX;

        for (int x : nums) {
            // two maximums
            if (x >= firstMax) {
                secondMax = firstMax;
                firstMax = x;
            }
            else if (x > secondMax) 
                secondMax = x;

            // two minimums
            if (x <= firstMin) {
                secondMin = firstMin;
                firstMin = x;
            }
            else if (x < secondMin)
                secondMin = x;
        }

        return (firstMax * secondMax) - (firstMin * secondMin);
    }
};