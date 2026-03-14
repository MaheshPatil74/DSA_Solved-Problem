// LeetCode 1415 — “The k-th Lexicographical String of All Happy Strings of Length n” (Medium)

// Approach 1 : Sabse best and Optimal
// TC : O(N) , SC : O(1)
class Solution {
public:
    string getHappyString(int n, int k) {
        int totalString = 3 * pow(2,n-1) ;
        if( k>totalString )
            return "";

        string res = "" ;
        vector<char> chars = { 'a' , 'b' , 'c' };

        int block = pow( 2 , n-1 );
        int index = (k-1)/block ;

        res += chars[index] ;

        k = (k-1)%block + 1 ;       //skipped blocks

        for( int i = 1 ; i<n ; i++ ){
            vector<char> next ;
            for( char temp : chars )
                if( temp != res.back() )
                    next.push_back( temp ) ;

            block /= 2 ;
            index = (k-1)/block ;
            res += next[index] ;
            k = (k-1)%block + 1 ;            
        }
        return res ;
    }
};