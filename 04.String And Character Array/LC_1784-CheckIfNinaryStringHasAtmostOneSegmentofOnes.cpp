// TC : O(N) , SC : O(1)
class Solution {
public:
    bool checkOnesSegment(string s) {
        bool zeroIntro = false ;
        for( char ch : s ){
            if( ch == '0' )
                zeroIntro = true ;

            if( zeroIntro && ch == '1' )
                return false ;
        }
        return true ;
    }
};