// Appproach 1 : Sort and Swap Adjacent
// TC : O( N*LogN ) , SC : O(1)
class Solution {
public:
    vector<int> numberGame(vector<int>& nums) {
        sort( nums.begin() , nums.end() ) ;
        for( int i = 0 ; i<nums.size() ; i+=2 )
            swap( nums[i] , nums[i+1] );
        return nums ;
    }
};