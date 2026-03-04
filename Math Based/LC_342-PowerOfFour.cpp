// Approach 2 : Bitwise approach
// TC : O( 1 ) , SC : O(1)
class Solution {
public:
    bool isPowerOfFour(int n) {
        return n > 0 &&
               (n & (n - 1)) == 0 &&   // power of 2
               (n & 0x55555555);      // even bit position
    }
};


// Approach 1 : better approach
// TC : O( LogN With base 4 ) , SC : O(1)
class Solution {
public:
    bool isPowerOfFour(int n) {
        if(n <= 0) return false;

        while(n % 4 == 0)
            n /= 4;

        return n == 1;
    }
};