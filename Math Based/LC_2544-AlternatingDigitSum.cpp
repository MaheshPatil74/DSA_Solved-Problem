// Approach 1 : 
// TC : O(d) , SC : O(1)
class Solution {
public:
    int alternateDigitSum(int n) {
        int count = 0 , sum = 0 , temp = n ;
        while( temp > 0 ){
            count++ ;
            int digit = temp % 10 ;
            sum = ( count & 1 ) ? sum + digit : sum - digit ;
            temp /= 10 ;
        } 
        return ( count%2 ) ? sum : -sum ;
    }
};