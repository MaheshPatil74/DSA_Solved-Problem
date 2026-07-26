// TC : O(N) , SC : O(1)
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        long long max1 = INT_MIN , max2 = INT_MIN ;

        for( int x : nums ){
            if( x >= max1 ){
                max2 = max1 ;
                max1 = x ;
            }
            else if( x >= max2 ){
                max2 = x ;
            }
        }
        return ( (max1-1) * (max2-1) ) ;
    }
};