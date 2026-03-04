// Approach 2 : Encoding-Decoding (Without Using Extra Array) 
// Time Complexity: O(n)    
// Space Complexity: O(1)
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size() ;
        
        for (int i = 0; i < nums.size(); i++) 
            nums[i] += (n * (nums[nums[i]] % n));
        
        for (int i = 0; i < nums.size(); i++) 
            nums[i] /= n;
        
        return nums;
    }
};



// Approach 1 : Using Extra Array
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    vector<int> buildArray(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> ans(n) ;

        for( int i = 0 ; i<n ; i++ ){
            int temp = nums[i] ;
            ans[i] = nums[temp] ;
        }
        return ans ;
    }
};