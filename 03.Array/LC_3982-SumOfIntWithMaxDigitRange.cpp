// TC : O(N*d) , SC : O(1)
class Solution {
public:
    int maxDigitRange(vector<int>& nums) {
        int maxDiff = INT_MIN ;
        long long sum = 0 ;
        for( int i = 0 ; i<nums.size() ; i++ ){
            int maxDigit = INT_MIN , minDigit = INT_MAX ;
            int temp = nums[i] ;
            while( temp>0 ){
                int currDigit = temp%10 ;
                maxDigit = max(maxDigit , currDigit) ;
                minDigit = min(minDigit , currDigit) ;
                temp/= 10 ;
            }
            int diff = maxDigit - minDigit ;
            if( diff > maxDiff ){
                maxDiff = diff ;
                sum = nums[i] ;
            }
            else if (diff == maxDiff){
                sum += nums[i] ;
            }
        }
        return sum ;
    }
};