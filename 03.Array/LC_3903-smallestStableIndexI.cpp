// Approach 2 : Slightly Optimised Space
// TC : O(N) , SC : O(N)
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size() ;
        vector<int> mini = nums ;
        for( int i = n-2 ; i>=0 ; i-- )
            mini[i] = min( mini[i] , mini[i+1] ) ; 

        int maxi = nums[0] ;
        for( int i = 0 ; i<n ; i++ ){
            maxi = max( maxi , nums[i] ) ;
            if( (maxi - mini[i]) <= k )
                return i ;
        }
        return -1 ;
    }
};

// Approach 1 : By making max and min array
// TC : O(N) , SC : O(N)
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size() ;
        vector<int> maxi = nums ;
        vector<int> mini = nums ;

        for( int i = 1 ; i<n ; i++ ){
            maxi[i] = max( maxi[i] , maxi[i-1] ) ;
            mini[n-i-1] = min( mini[n-i-1] , mini[n-i] ) ; 
        }

        for( int i = 0 ; i<n ; i++ )
            if( (maxi[i] - mini[i]) <= k )
                return i ;
        return -1 ;
    }
};