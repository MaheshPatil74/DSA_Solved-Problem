// TC : O(N) , SC : O(1)
class Solution {
public:
    int maximizeSum(vector<int>& nums, int k) {
        int maxi = INT_MIN ;
        for( int num : nums )
            maxi = max( maxi , num ) ;

        long long ans = 0 ;
        for( int i = 0 ; i<k ; i++ )
            ans += maxi++ ;
        return ans ;
    }
};