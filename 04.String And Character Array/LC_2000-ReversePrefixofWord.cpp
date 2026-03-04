
// Time Complexity : O(N)
// Space Complexity : O(1)
class Solution {
private :
    string reverseString( string word , int start , int end ){
        while( start < end )
            swap( word[start++] , word[end--] );
        return word ;
    }
public:
    string reversePrefix(string word, char ch) {
        
        int index = 0 ;
        while( index < word.length() ){
            if( word[index] == ch )
                break ;
            index++ ;
        }
        if( index == word.length() )
            return word ;
        
        return reverseString(word , 0 , index );
    }
};