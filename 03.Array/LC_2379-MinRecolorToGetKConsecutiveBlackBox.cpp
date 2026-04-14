// Appproach 2 : Sliding Window 
// TC : O( N ) , SC : O(1)
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size() ;
        int white = 0 ;

        // first window
        for( int i = 0 ; i<k ; i++ )
            if( blocks[i] == 'W' )
                white++ ;

        int ans = white ;
        for( int i = k ; i<n ; i++ ){
            if( blocks[i] == 'W' )
                white++ ;
            if( blocks[i-k] == 'W' )
                white-- ;

            ans = min( ans , white ) ;
        }
        return ans ;
    }
};


// Appproach 1 : Make Window And Then count White 
// TC : O( N*K ) , SC : O(1)
class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int n = blocks.size() ;
        int ans = INT_MAX ;
        for( int i = 0 ; i<= n-k ; i++ ){
            int white = 0 ;
            for( int j = i ; j<i+k ; j++ )
                if( blocks[j] == 'W' )
                    white++ ;
            ans = min( ans , white ) ;
        }
        return ans ;
    }
};