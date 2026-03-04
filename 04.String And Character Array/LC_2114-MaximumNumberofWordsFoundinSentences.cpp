// Time Complexity: O(n*m) where n is the number of sentences and m is the average length of each sentence.
// Space Complexity: O(1) as we are using only a constant amount of extra space
class Solution {
public:
    int mostWordsFound(vector<string>& sentences) {
        int maxi = -1 ;
        for( int i = 0 ; i<sentences.size() ; i++ ){
            int spaces = 0 ; 
            for( int j = 0 ;j<sentences[i].length() ; j++ ){
                if( sentences[i][j] == ' ' )
                    spaces++ ;
            }
            maxi = max( maxi , spaces+1 ) ;
        }
        return maxi ;
    }
};