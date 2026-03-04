// Approach 1 :
// TC : O( N*M )  , SC : O(N*M)
class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> data ;

        vector<string> morse = { ".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."} ;

        for( string word : words ){
            string temp = "" ;
            for( char ch : word )
                temp +=  morse[ch-'a'] ;
            data.insert(temp) ;
        }
        return data.size() ;
    }
};