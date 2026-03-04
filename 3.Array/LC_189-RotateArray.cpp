// Approach-2 : Without Using Extra Array
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;

        reverse(nums.begin(), nums.end());
        reverse(nums.begin(), nums.begin() + k);
        reverse(nums.begin() + k, nums.end());
    }
};


// Approach-1 : Using Extra Array
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        int n = nums.size() ;
        vector<int> temp(n) ;
        for( int i = 0 ; i<n ; i++ )
            temp[ (i+k)%n ] = nums[i] ;
        nums = temp ;
    }
};