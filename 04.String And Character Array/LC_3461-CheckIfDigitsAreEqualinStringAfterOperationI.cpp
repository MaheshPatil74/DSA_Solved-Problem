// TC : O(N*N) , SC : O(N)
class Solution {
public:
    bool hasSameDigits(string s) {
        
        while( s.length() != 2 ){
            string temp = "" ;
            for( int i = 0 ; i+1<s.length() ; i++ )
                temp.push_back((( (s[i]-'0') + (s[i+1]-'0') )% 10) + '0' ) ;
            s = temp ;
        }

        return ( s[0] == s[1] ) ;
    }
};