// TC : O(LogN) , SC : O(1)
class Solution {
public:
    int mirrorDistance(int n) {
        int rev = 0 ;
        int orig = n ;

        while( orig != 0 ){
            int digit = orig%10  ;
            rev = rev*10 + digit ;
            orig /= 10 ;
        }
        return abs( n-rev );
    }
};