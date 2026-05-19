// TC : O( N*d ) , SC : O(1)
class Solution {
public:
    int sumOfEncryptedInt(vector<int>& nums) {
        long long totalSum = 0 ;

        for( int num : nums ){
            int temp = num ;
            int maxDigit = 0 ;
            int digits = 0 ; 

            while( temp > 0 ){
                maxDigit = max( maxDigit , temp % 10 ) ;
                digits++ ;
                temp /= 10 ;
            }

            int encrypted = 0 ;
            while( digits-- )
                encrypted = encrypted*10 + maxDigit ;

            totalSum += encrypted ;
        }

        return totalSum ;
    }
};