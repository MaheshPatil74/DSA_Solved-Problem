// TC : O(N)
class Solution {
public:
    int countAsterisks(string s) {
        int count = 0 ;
        int i = 0 ;
        while( i<s.length() ) {
            if( s[i] == '*' ){
                count++ ;
            }
            else if( s[i] == '|' ){
                i++;
                while( i<s.length() && s[i] != '|'){
                    i++;
                }
            }
            i++ ;
        }
        return count ;
    }
};