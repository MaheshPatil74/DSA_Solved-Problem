// TC : O( LogN ) ,SC : O(1)
class Solution {
public:
    long long removeZeros(long long n) {
        long long num = 0 , place = 1 ;
        while(n > 0){
            int digit = n % 10;
            if(digit != 0){
                num = ( digit * place ) + num ;
                place *= 10 ;
            }
            n /= 10;
        }
        return num;
    }
};