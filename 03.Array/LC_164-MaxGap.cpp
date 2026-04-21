// Approach 2 : Optimal According to question requirement
// TC : O(N) , SC : O(N) 


// Approach 1 : using Sorting <<== Not fullfill question requirement of linear complexity
// TC : O(N*LogN) , SC : O(1) 
class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int n = nums.size() ;
        if( n < 2 )     return 0 ;

        sort( nums.begin() , nums.end() );
        int maxDiff = 0 ;
        for( int i = 1 ; i<n ; i++ )
            maxDiff = max( maxDiff , nums[i]-nums[i-1] ) ;
        return maxDiff ;
    }
};