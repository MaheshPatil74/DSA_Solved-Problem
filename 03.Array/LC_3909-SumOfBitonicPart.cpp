// TC : O(N) , SC : O(1)
class Solution {
public:
    int compareBitonicSums(vector<int>& nums) {
        long long sumAsc = nums[0] , sumDsc = 0 ;

        int i = 1 ;
        while( i<nums.size() && nums[i-1] < nums[i] ){
            sumAsc += nums[i] ;
            i++ ;
        }

        // now , "i-1" is index of peak element
        sumDsc = nums[i-1] ;
        while( i<nums.size() && nums[i-1] > nums[i] ){
            sumDsc += nums[i] ;
            i++ ;
        }

        if( sumAsc == sumDsc )
            return -1 ;
        else if( sumAsc > sumDsc )
            return 0 ;
        return 1 ;
    }
};