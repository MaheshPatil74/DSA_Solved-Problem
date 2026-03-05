// TC : O(N+M+K) , SC : O(1)
class Solution {
    int wordVal( string& word ){
        int ans = 0 ;
        for( char ch : word )
            ans = (ans*10) + ( ch - 'a' );
        return ans ;
    }

public:
    bool isSumEqual(string firstWord, string secondWord, string targetWord) {
        int firstWordVal = wordVal(firstWord);
        int secondWordVal = wordVal(secondWord);
        int targetWordVal = wordVal(targetWord);

        return ( firstWordVal+secondWordVal) == targetWordVal ;
    }
};