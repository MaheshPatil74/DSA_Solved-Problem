class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "" ;

        if( words.size() == 0 )
            return ans ;
        
        for( int i = 0 ; i<words.size() ; i++ ){
            int sum = 0 ;
            for( char temp : words[i] )
                sum += weights[ temp - 'a' ];
            ans.push_back( 'z' - (sum%26) ) ;
        }
        return ans ;
    }
};