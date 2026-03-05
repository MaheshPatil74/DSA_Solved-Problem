// Logic : Jaise hi string me "b" mil jaye, uske baad agar kabhi "a" aaye to string invalid hai.
// TC : O(N) , SC : O(1)
class Solution {
public:
    bool checkString(string s) {
        bool introB = false ;

        for( char ch : s ){
            if( ch == 'b' )
                introB = true ;

            if( introB && ch == 'a' )
                return false ;
        }
        return true ;
    }
};