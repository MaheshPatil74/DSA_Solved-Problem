// Approach 2 : Optimal DP Optimal Used
// TC : O(N)
class Solution {
public:
    int countLetters(string s) {
        int total = 1, count = 1;
        for (int i = 1; i < s.length(); i++) {
            if (s[i] == s[i-1]) 
                count++; 
            else 
                count = 1;
            total += count;
        }
        return total;
    }
};

// Approach 1 : Brute Force
// TC : O(N*N)
class Solution {
public:
    int countLetters(string s) {
        int count = 0 ;

        for( int i = 0 ; i<s.length() ; i++ ){
            for( int j = i ; j<s.length() ; j++ ){
                if( s[i] == s[j] )
                    count++ ;
                else
                    break ;
            }
        }
        return count ;
    }
};
