// TC : O(N) , SC : O(1)
class Solution {
public:
    bool isMiddleElementUnique(vector<int>& nums) {
        int n = nums.size() ;
        int middleElement = nums[n/2] ;
        int count = 0 ;
        for( int num : nums ){
            if( num == middleElement )
                count++ ;
            if( count > 1 )
                return false ;
        }
        return true ;
    }
};