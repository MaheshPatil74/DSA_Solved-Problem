// Approach 1 :
// Time: O(n) → each character at most 2 baar visit
// Space: O(1) → in-place swap
class Solution {
public:
    string reverseByType(string s) {
        int i = 0 ;
        int j = s.length()-1 ;

        while( i<j ){
            while( ( i<s.length() ) && ( s[i] < 'a' || s[i] > 'z' ) ) 
                i++ ;
            while( (j>=0) && ( s[j] < 'a' || s[j] > 'z' ) ) 
                j-- ;
            
            if( i<j )
                swap( s[i++] , s[j--] );
        }

        i = 0 , j = s.length() - 1 ;
        while( i<j ){
            while( i<s.length() && s[i] >= 'a' && s[i] <= 'z' ) 
                i++ ;
            while( j>=0 && s[j] >= 'a' && s[j] <= 'z' ) 
                j-- ;
            
            if( i<j )
                swap( s[i++] , s[j--] );
        }
        return s ;
    }
};