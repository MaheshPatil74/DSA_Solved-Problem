// lOGIC : 
// From 1 to num, almost half numbers have even digit sum. So start with num / 2.
// But result depends on digit sum of num:
// If digit sum of num is odd, exclude last number & IF even, include it.
// Final formula:  (num - (digitSum(num) % 2)) / 2
// TC : O( Log(num) ) , SC : O(1)
class Solution {
public:
    int countEven(int num) {
        int sum = 0 , x = num ;
        while( x>0 ){
            sum += ( x%10 ) ;
            x /= 10 ;
        }
        return ( num - (sum%2) ) / 2 ;
    }
};