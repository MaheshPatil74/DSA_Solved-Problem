class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        
        int maxi = 0 ;
        int i = 0 ;
        int count = 0 ;

        while( i<nums.size() ){
            if( nums[i] == 1 ){
                count++ ;
            }
            else if( nums[i] == 0 ){
                maxi = max( maxi , count ) ;
                count = 0 ;
            }
            i++ ;
        }
        maxi = max( maxi , count ) ;

        return maxi ;
    }
};