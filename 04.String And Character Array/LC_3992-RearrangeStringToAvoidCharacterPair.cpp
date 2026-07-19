// TC : O(N) , SC : O(1)
class Solution {
public:
    string rearrangeString(string s, char x, char y) {
        int left = 0 , right = s.length()-1 ;

        while( left < right ){
            while( left < right && s[left] != x )
                left++ ;

            while( left < right && s[right] != y )
                right-- ;
            
            if( left < right )
                swap( s[left] , s[right] );
        }

        return s ;
    }
};