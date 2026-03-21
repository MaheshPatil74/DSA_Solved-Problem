// Approach 2 : using monotonic stack 
// TC : O(N) , SC : O(N)



// Approach 1 : 
// TC : O(N*N) , SC : O(1)
class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        long long result = 0 ;
        for( int i = 0 ; i<nums.size() ; i++ ){
            int maxi = INT_MIN ;
            int mini = INT_MAX ;
            for( int j = i ; j<nums.size() ; j++ ){
                mini = min( mini , nums[j] ) ;
                maxi = max( maxi , nums[j] ) ;
                result += ( maxi - mini ) ;
            }
        }
        return result ;
    }
};