// Approach-2: Two Pointer Technique to compare characters without extra space.
// Time Complexity: O(n + m) where n and m are the total lengths of word1 and word2 respectively.
// Space Complexity: O(1)
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int i = 0 , j = 0 ;
        int p = 0 , q = 0 ;

        while( i<word1.size() && j<word2.size() ){
            if( word1[i][p] != word2[j][q] )
                return false ;  
            p++ ;
            q++ ;

            if( p == word1[i].size() ){
                i++ ;
                p = 0 ;
            }
            if( q == word2[j].size() ){
                j++ ;
                q = 0 ;
            }
        }   

        return i==word1.size() && j==word2.size() ;    
    }
};


// Approach-1: Concatenate both string arrays and then compare the resultant strings.
// Time Complexity: O(n + m) where n and m are the total lengths of word1 and word2 respectively.
// Space Complexity: O(n + m) for storing the concatenated strings.
class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        string first = "" ;
        for( string word : word1 )
            first += word ;

        string second = "" ;
        for( string word : word2 )
            second += word ;

        // int firstLength = first.length() ;
        // int secondLength = second.length() ;
        // if( firstLength != secondLength )
        //     return false ;
        // int i = 0 ;
        // int j = 0 ;
        // while( i<firstLength && j<secondLength ){
        //     if( first[i] != second[j] )
        //         return false ;
        //     i++ ;
        //     j++ ;
        // }

        if( first != second )
            return false ;
        return true ;        
    }
};