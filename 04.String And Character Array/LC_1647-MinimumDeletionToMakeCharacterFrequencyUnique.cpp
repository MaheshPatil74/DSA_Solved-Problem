// TC : O(N) , SC : O(N)
class Solution {
public:
    int minDeletions(string s) {
        vector<int> freq(26,0) ;
        for( char ch : s )
            freq[ ch - 'a' ]++ ;

        int deletion = 0 ;
        unordered_set<int> st ;
        for( int f : freq ){
            while( f>0 && st.count(f) ){
                deletion++ ;
                f-- ;
            }
            st.insert( f ) ;
        }
        return deletion ;
    }
};