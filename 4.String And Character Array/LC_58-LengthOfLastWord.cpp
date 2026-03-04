// Approach 1 : (My Own Approach )Optimal said by Chatgpt
// T.C. = O(N) , S.C. = O(1)
class Solution {
public:
    int lengthOfLastWord(string s) {
        int n = s.length() ;

        int i = n-1 ;
        while( i>=0 && s[i] == ' ' ){
            i--;
        }

        int count = 0 ;
        while( i>=0 && s[i] != ' ' ){
            count++ ;
            i-- ;
        }
        return count ;
    }
};