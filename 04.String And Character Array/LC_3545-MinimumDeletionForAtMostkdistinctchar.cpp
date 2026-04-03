// TC : O(N) , SC : O(1)
class Solution {
public:
    int minDeletion(string s, int k) {
        vector<int> freq( 26 , 0 ) ;
        int distinctChar = 0 ;
        for( char ch : s ){
            if( freq[ch-'a'] == 0 )
                distinctChar++ ;
            freq[ch-'a']++ ;
        }

        if( distinctChar <= k )
            return 0 ;

        int diff = distinctChar-k ;
        sort( freq.begin() , freq.end() );

        int deletion = 0 ;
        int temp = 0 ;
        for( int i = 0 ; i<26 ; i++ ){
            if( freq[i] != 0 && ( temp<diff) ){
                deletion += freq[i] ;
                temp++ ;
            }
            else if( temp >= diff )
                break ;
        }
        return deletion ;
    }
};