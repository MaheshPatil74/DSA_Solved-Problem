// TC : O(N*LogN) , SC : O(n)
class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size() ;
        int maxi = nums[0] ;
        vector<int> prefix(n) ;
        for( int i = 0 ; i<n ; i++ ){
            maxi = max( maxi , nums[i] ) ;
            prefix[i] = gcd( maxi , nums[i] ) ;
        }

        sort( prefix.begin() , prefix.end() );

        long long sum = 0 ;
        int left = 0 , right = n-1 ;
        while( left < right ){
            sum += gcd( prefix[left++] , prefix[right--] ) ;
            // left++ ;
            // right-- ;
        }
        return sum ;
    }
};