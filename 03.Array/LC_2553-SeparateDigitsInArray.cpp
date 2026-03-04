// Approach 2 : more optimal uisng string builtIn Operation
// TC : O(N) , SC : O(N)
class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> ans;
        for(int num : nums){
            string s = to_string(num);
            for(char ch : s)
                ans.push_back(ch - '0');
        }
        return ans;
    }
};


// Approach 1 : 
// TC : O(N) , SC : O(N)
class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n = nums.size() ;
        vector<int> ans ;

        for( int i = n-1 ; i>=0 ; i-- ){
            int temp = nums[i] ;
            while( temp != 0 ){
                ans.push_back( temp % 10 ) ;
                temp /= 10 ;
            }
        }

        int left = 0 ;
        int right = ans.size()-1 ;
        while( left < right )
            swap( ans[left++] , ans[right--] );

        return ans ;
    }
};