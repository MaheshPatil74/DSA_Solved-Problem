// Approach 3 : Most Optimal ==> half reverse
// TC : O( LogN ) , SC : O(1)
class Solution {
public:
    bool isPalindrome(int x) {
        // Negative number ya last digit 0 ho (except 0 itself)
        if(x < 0 || (x % 10 == 0 && x != 0))
            return false;
        int reversedHalf = 0;
        while(x > reversedHalf) {
            reversedHalf = reversedHalf * 10 + x % 10;
            x /= 10;
        }
        // Even digits → x == reversedHalf
        // Odd digits → middle digit remove → reversedHalf/10
        return (x == reversedHalf || x == reversedHalf / 10);
    }
};



// Approach 2 : full using revesed Number
// TC : O( LogN ) , SC : O(1)
class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false ;
        long long int originalNum = x ;
        long long int reverseNum = 0 ;
        while(x>0){
            int digit = x % 10 ;
            reverseNum = reverseNum*10 + digit ;
            x = x/10 ;
        }
        return ( reverseNum==originalNum ) ;
    }
};


// Approach 1 : using extra string using built in method
// TC : O(N) , SC : O(N)
class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x) ;
        int l = 0  , r = s.length()-1 ;
        while( l<r ){
            if( s[l] != s[r] )
                return false ;
            l++ ;
            r-- ;
        }
        return true ;
    }
};