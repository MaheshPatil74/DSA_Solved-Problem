// TC : O(N) , SC : O(1)
class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<bool> lower(26,false) ;
        vector<bool> upper(26,false) ;

        for( char ch : word ){
            if( ch >= 'a' && ch <= 'z' )
                lower[ ch-'a' ] = true ;
            else
                upper[ ch-'A' ] = true ;
        }

        int count = 0 ;
        for( int i = 0 ; i<26 ; i++ )
            if( upper[i] && lower[i] )
                count++ ;
        return count ;
    }
};