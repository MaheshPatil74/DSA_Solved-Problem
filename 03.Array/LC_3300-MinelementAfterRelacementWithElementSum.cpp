// TC : O(N * d) , SC : O(1)
class Solution {
public:
    int minElement(vector<int>& nums) {
        int minDigitSum = INT_MAX ;
        
        for( int num : nums ){
            int digitSum = 0 ;
            while( num > 0 ){
                digitSum += num % 10 ;
                num /= 10 ;
            }
            minDigitSum = min( minDigitSum , digitSum ) ;
        }
        return minDigitSum;
    }
};