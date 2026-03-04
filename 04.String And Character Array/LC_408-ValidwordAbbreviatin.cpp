// TC : O( N + M )
class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int n = word.length() ;
        int m = abbr.length() ;

        int i = 0 ;
        int j = 0 ;

        while( i<n && j<m ){
            if( abbr[j] == '0' )
                return false ;
            
            if( isalpha( abbr[j] ) ){
                if( word[i] != abbr[j] )
                    return false ;
                i++ ;
                j++ ;
            }
            else{
                int subLen = 0 ;
                while( j<m && isdigit(abbr[j]) ){
                    subLen = subLen*10 + ( abbr[j] - '0' ) ;
                    j++ ;
                }
                i += subLen ;
            }
        } 
        return ( i==n && j==m);
    }
};