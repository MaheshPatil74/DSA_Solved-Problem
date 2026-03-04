// TC : O(N*N) , SC : O(1)
class Solution {
public:
    bool validWordSquare(vector<string>& words) {
        int n = words.size() ;

        for( int i = 0 ; i<n ; i++ ){
            for( int j = 0 ; j<words[i].length() ; j++ ){
                // Safety checks
                if(j >= n || i >= words[j].size())
                    return false;
                if( words[i][j] != words[j][i] )
                    return false ;
            }
        }
        return true ;
    }
};
