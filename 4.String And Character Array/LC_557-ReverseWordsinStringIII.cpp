// Time Complexity : O(N) , Space Complexity : O(1)
class Solution {
private :
    void reverseString(string &s , int i , int j ){
        while( i<j )
            swap( s[i++] , s[j--] );
    }

public:
    string reverseWords(string s) {
        int start = 0 ;
        for( int i = 0 ; i<s.length() ; i++ ){
            if( s[i] == ' '){
                reverseString(s , start , i-1 ) ;
                start = i+1 ;
            }
            if( i==s.length()-1)
                reverseString(s , start , i ) ;
        }
        return s ;
    }
};