// TC : O( LogN ) ,SC : O(1)
class Solution {
public:
    long long sumAndMultiply(int n) {
        long long num = 0 , sum = 0 , place = 1 ;
        while(n > 0){
            int digit = n % 10;
            if(digit != 0){
                sum += digit;
                num = ( digit * place ) + num ;
                place *= 10 ;
            }
            n /= 10;
        }
        return sum * num;
    }
};