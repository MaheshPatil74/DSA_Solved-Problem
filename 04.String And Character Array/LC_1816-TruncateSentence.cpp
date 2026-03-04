// TC : O(N) , SC : O(1)
class Solution {
public:
    string truncateSentence(string s, int k) {
        int spaces = 0 ;
        int index = 0 ;
        for( int index = 0 ; index < s.length() ; index++ ){
            if( s[index] == ' ' ){
                spaces++ ;
                if( spaces == k )
                    return s.substr(0,index) ;
            }   
        }
        return s;
    }
};