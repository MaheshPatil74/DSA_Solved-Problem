// TC : O(N) , SC : O(1)
class Solution {
public:
    int vowelConsonantScore(string s) {
        int v = 0 ;
        int c = 0 ;
        for( char ch : s ){
            if( ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' )
                v++ ;
            else if( isalpha(ch) )
                c++ ;
        }

        return ( c==0 ) ? 0 : v/c ;
    }
};