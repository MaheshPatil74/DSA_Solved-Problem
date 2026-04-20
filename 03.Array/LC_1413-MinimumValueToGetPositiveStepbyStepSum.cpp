// Approach : Sabse optimal
// TC : O(N) , SC : O(1)
class Solution {
public:
    int minStartValue(vector<int>& nums) {
        long long mini = 0 , sum = 0 ;
        for( int num : nums ){
            sum += num ;
            mini = min( mini , sum ) ;
        }
        return 1-mini ;
    }
};