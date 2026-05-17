// TC : O(N) , SC : O(1)
class Solution {
public:
    bool checkAlmostEquivalent(string word1, string word2) {
        int n = word1.size() ;
        vector<int> first(26,0) ;
        vector<int> second(26,0) ;

        for( int i = 0 ; i<n ; i++ ){
            first[ word1[i] - 'a' ]++ ;
            second[ word2[i] - 'a' ]++ ;
        }

        for( int i = 0 ; i<26 ; i++ )
            if( abs(first[i] - second[i] ) > 3 )
                return false ;
        return true ;
    }
};