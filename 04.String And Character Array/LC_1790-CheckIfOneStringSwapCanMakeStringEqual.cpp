// Approach 2 : mismatch check
// TC  : O(N) , SC : O(1)
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        int first = -1 , second = -1 ;

        for( int i = 0 ; i<s1.length() ; i++ ){
            if( s1[i] != s2[i] ){
                if( first == -1 )
                    first = i ;
                else if( second == -1 ) 
                    second = i ;
                else
                    return false ;
            }
        }
        if( first == -1 )   return true ;
        if( second == -1 )  return false ;

        return (s1[first] == s2[second]) && (s1[second] == s2[first]) ;
    }
};



// Approach 1 : frequency array + mismatch check
// TC  : O(N) , SC : O(26)==O(1)
class Solution {
public:
    bool areAlmostEqual(string s1, string s2) {
        // checks all alphabets are same in both string
        vector<int> present(26,0) ;
        for( char ch : s1 )
            present[ ch - 'a' ]++ ;

        for( char ch : s2 ){
            if( present[ ch-'a' ] == 0 )
                return false ;
            present[ch-'a']-- ;
        }

        // find indices where chars are diffrent
        int countDiff = 0 ;
        for( int i = 0 ; i<s1.length() ; i++ ){
            if( s1[i] != s2[i] ){
                countDiff++ ;
                if( countDiff>2 )
                    return false ;
            }
        }
        return true ;
    }
};