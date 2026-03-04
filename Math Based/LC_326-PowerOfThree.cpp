// Approach 2 : Advance approach
// TC : O( 1 ) , SC : O(1)
class Solution {
public:
    bool isPowerOfThree(int n) {
        return n > 0 && 1162261467 % n == 0;
    }
};

// Approach 1 : better approach
// TC : O( LogN With base 3 ) , SC : O(1)
class Solution {
public:
    bool isPowerOfThree(int n) {
        if( n<=0 )
            return false ;
        while( n%3 == 0 )
            n/=3 ;
        return (n==1) ;
    }
};