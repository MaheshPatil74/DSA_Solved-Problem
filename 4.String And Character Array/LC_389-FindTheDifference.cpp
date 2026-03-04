// Approach 2: Using XOR
// Time Complexity : O(n)   
// Space Complexity : O(1)
class Solution {
public:
    char findTheDifference(string s, string t) {
        char ans = 0 ;

        for( char c : s )
            ans = ans ^ c ;
        
        for( char c : t )
            ans = ans ^ c ;

        return ans ;
    }
};



// Approach1: Using Sum of ASCII values
// Time Complexity : O(n)
// Space Complexity : O(1)
class Solution {
public:
    char findTheDifference(string s, string t) {
        int sum1 = 0 ;
        int i = 0 ;
        while( i<s.length() ){
            int ch = s[i] ;
            sum1 += ch ;
            i++ ;
        }

        int sum2 = 0 ;
        int j = 0 ;
        while( j<t.length() ){
            int ch = t[j] ;
            sum2 += ch ;
            j++ ;
        }

        char ans = sum2-sum1 ;
        return ans ;
    }
};