// TC : O(N) , SC : O(1)
class Solution {
public:
    string largestEven(string s) {
        for( int i = s.length()-1 ; i>=0 ; i-- ){
            if( s[i] == '2' )
                return s ;
            s.pop_back() ;
        }
        return "";
    }
};