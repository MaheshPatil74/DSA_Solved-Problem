// Approach 2 :
// Same But slight compact version
// Time Complexity: O(N) , Space Complexity: O(1)
class Solution {
private:
    bool isVowel(char ch) {
        return ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'
            || ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U';
    }
public:
    bool halvesAreAlike(string s) {
        int mid = s.length() / 2;
        int count = 0;  // will store difference between first and second half
        for (int i = 0; i < mid; i++) {
            if (isVowel(s[i])) count++;
            if (isVowel(s[i + mid])) count--;
        }
        return count == 0;
    }
};

// Approach 1 :
// Original Version
// Time Complexity: O(N) , Space Complexity: O(1)
class Solution {
private :
    bool isVowel( char ch ){
        if( ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U' )
            return true ;
        return false ;
    }
public:
    bool halvesAreAlike(string s) {
        
        int mid = s.length() / 2 ;

        int vowelFirst = 0 ;
        for( int i = 0 ; i < mid ; i++ ){
            if( isVowel(s[i]) )
                vowelFirst++ ;
        }

        int vowelSecond = 0 ;
        for( int i = mid ; i < s.length() ; i++ ){
            if( isVowel(s[i]) )
                vowelSecond++ ;
        }

        return vowelSecond==vowelFirst ;
    }
};