// TC : O(N) , SC: O(1)
class Solution {
private : 
    bool isVowel( char temp ){
        if( temp == 'a' || temp == 'e' || temp == 'i' || temp == 'o' || temp == 'u' )
            return true ;
        return false ;
    }
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        int count = 0 ;
        for( int i = left ; i<=right ; i++ ){
            string word = words[i] ;
            if( isVowel(word[0]) && isVowel( word[word.length()-1] ) ) {
                count++ ;
            }
        }
        return count ;
    }
};