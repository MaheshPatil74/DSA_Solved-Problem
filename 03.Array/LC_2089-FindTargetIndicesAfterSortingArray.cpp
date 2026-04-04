// Approach 2 : Optimal ==>> counting trick
// TC : O(N) , SC : O(1)
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        int n = nums.size() ;
        int less = 0 , equal = 0 ;
        for( int num : nums ){
            if( num == target ) equal++ ;
            else if( num < target ) less++ ;
        }

        vector<int> ans ;
        for( int i = 0 ; i<equal ; i++ )
            ans.push_back(less++) ;
        return ans ;
    }
};


// Approach 1 : Brute force ==>> actual sorting
// TC : O(N*LogN) , SC : O(1)
class Solution {
public:
    vector<int> targetIndices(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for(int i = 0; i < nums.size(); i++)
            if(nums[i] == target)
                ans.push_back(i);
        return ans;
    }
};