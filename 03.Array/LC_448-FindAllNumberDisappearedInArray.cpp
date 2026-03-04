// Approach 2 : Marking Technique
// TC : O(N) 
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans;

        // Mark visited indices
        for(int i = 0; i < nums.size(); i++) {
            int index = abs(nums[i]) - 1;

            if(nums[index] > 0)
                nums[index] = -nums[index];
        }

        // Jo index positive reh gaye → wo missing numbers
        for(int i = 0; i < nums.size(); i++) {
            if(nums[i] > 0)
                ans.push_back(i + 1);
        }

        return ans;
    }
};


// Approach 1 : sort
// TC : O(NLogN) 
class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int> ans ;

        sort( nums.begin() , nums.end() );
        
        // loops to check "j" is present in Nums or Not
        int idx = 0 ;     //indicate index of nums
        int j = 1 ;
        while( idx < nums.size() ){
            if( nums[idx] == j ){
                j++ ;
                idx++ ;
            }
            else if( nums[idx] < j )
                idx++ ;
            else
                ans.push_back(j++);
        }
        
        while( j<=nums.size() ) 
            ans.push_back(j++) ;
        
        return ans ;
    }
};