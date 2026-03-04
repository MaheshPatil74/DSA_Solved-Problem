// Approach 2: Using XOR
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int ans = nums.size();
        for (int i = 0; i < nums.size(); i++) 
            ans ^= i ^ nums[i];
        return ans;
    }
};

// Approach 1: Using Mathematical Formula
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size() ;

        // Sum of First n natural Number
        int numSum = ( n* (n+1)) / 2 ;
    
        // Sum of array
        int sumArray = 0 ;
        for( int num : nums )
            sumArray += num ;

        return numSum - sumArray ;
    }
};