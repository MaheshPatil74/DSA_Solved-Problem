// Approach 1 : 
// TC : O(N) , SC : O(1)
class Solution {
public:
    int maximizeExpressionOfThree(vector<int>& nums) {
        int a = INT_MIN , b = INT_MIN , c = INT_MAX ;
        for( int i = 0 ; i<nums.size() ; i++ ){
            if( nums[i] >= a ){
                b = a ;
                a = nums[i] ;
            }
            else if( nums[i] > b && nums[i] < a )
                b = nums[i] ;

            c = min( c , nums[i] ) ;
        }

        return ( a+b-c ) ;
    }
};