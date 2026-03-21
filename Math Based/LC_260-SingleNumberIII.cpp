// Approach 2 — Sorting
// TC : O(N*LogN) , SC : O(1)
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> ans;
        for(int i = 0; i < nums.size(); ){
            if(i + 1 < nums.size() && nums[i] == nums[i+1])
                i += 2;
            else {
                ans.push_back(nums[i]);
                i++;
            }
        }
        return ans;
    }
};

// Approach 1 — Brute Force (HashMap)
// Count frequency and return elements with frequency 1.
// TC : O(N) , SC : O(N)
class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        unordered_map<int,int> freq ;
        for( int num : nums )
            freq[num]++ ;

        vector<int> ans ;
        for( auto it : freq )
            if( it.second == 1 )
                ans.push_back(it.first) ;
        return ans ;
    }
};