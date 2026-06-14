// TC : O( D ) , SC : O(1)
class Solution {
public:
    bool checkGoodInteger(int n) {
        long long digitSum = 0 , squareSum = 0 ;

        while( n > 0 ){
            int digit = n%10 ;
            digitSum += digit ;
            squareSum += ( digit*digit ) ;
            n /= 10 ;
        }

        return ( squareSum - digitSum >= 50 ) ;
    }
};