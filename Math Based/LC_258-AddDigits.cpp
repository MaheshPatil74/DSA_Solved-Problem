// Approach 2 : optimal
// TC : O(1) , SC : O(1)
class Solution {
public:
    int addDigits(int num) {
        return ( num==0 ) ? 0 : 1 + (num - 1) % 9;
    }
};


// Approach 1 : Loop
// TC : O(LogN) , SC : O(1)
class Solution {
public:
    int addDigits(int num) {
        while( num >= 10 ){
            int sum = 0 ;
            while( num>0 ){
                sum += ( num%10 ) ;
                num /= 10 ;
            }
            num = sum ;
        }
        return num ;
    }
};