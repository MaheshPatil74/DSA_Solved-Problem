// TC : O(N) , SC : O(1)
class Solution {
public:
    string convert(string s, int numRows) {
        if( numRows == 1 )
            return s ;

        int n = s.size() ;
        string ans = "" ;
        int cycle = 2 * ( numRows - 1 ) ;

        for( int row = 0 ; row<numRows ; row++ ){
            for( int j = row ; j<n ; j+=cycle ){
                ans += s[j] ;

                int diag = j + cycle - ( 2*row ) ;
                if( row != 0 && row!=numRows-1 && diag<n )
                    ans += s[diag] ;
            }
        }
        return ans ;
    }
};