// TC : O(N*LogN) , SC : O(1)
class Solution {
public:
    int findFinalValue(vector<int>& nums, int original) {
        sort( nums.begin() , nums.end() );
        int n = nums.size() ;
        int i = 0 ;
        while( i < n ){
            
            while( i<n && nums[i] != original )
                i++ ;

            if( i<n )
                original *= 2 ;
            i++ ;
        }
        return original ;
    }
};