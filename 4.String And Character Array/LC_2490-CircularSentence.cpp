// Approach 2 : slight cleaner code
// TC : O(N) , SC : O(1)
class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.length() ;

        if( sentence[0] != sentence[n-1] )
            return false ;

        for( int i = 0 ; i<n ; i++ )
            if( sentence[i] == ' ')
                if( sentence[i-1] != sentence[i+1] )
                    return false ;
        return true ;
    }
};


// Approach 1 :
// TC : O(N) , SC : O(1)
class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.length() ;

        if( sentence[0] != sentence[n-1] )
            return false ;

        int i = 0 ;
        while( i+1<n ){

            while( i+1<n && sentence[i+1] != ' ' )
                i++ ;
            if( i+1 == n )
                return true ;
            if( sentence[i] != sentence[i+2] )
                return false ;
            i++ ;
        }
        return true ;
    }
};