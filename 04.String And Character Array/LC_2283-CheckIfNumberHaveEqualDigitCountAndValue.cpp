// TC : O(N) , SC : O(1)
class Solution {
public:
    bool digitCount(string num) {
        vector<int> freq(10,0) ;

        for( int i = 0 ; i<num.length() ; i++ )
            freq[ num[i] - '0' ]++ ;

        for( int i = 0 ; i<num.length() ; i++ )
            if( freq[i] != ( num[i] - '0' ) )
                return false ;
        return true ;
    }
};