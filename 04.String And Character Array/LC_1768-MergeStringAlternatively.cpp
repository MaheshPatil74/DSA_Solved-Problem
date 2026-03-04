// Appraoch 1 ==>> Not Optimized
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        int i = 0, j = 0;
        string ans = "";

        while (i < word1.length() || j < word2.length()) {
            if (i < word1.length()) {
                ans += word1[i++];
            }
            if (j < word2.length()) {
                ans += word2[j++];
            }
        }

        return ans;
    }
};


// Approach 2 : optimised for diffrence of string length is large
class Solution {
public:
    string mergeAlternately(string word1, string word2) {
        
        int n1 = word1.length() ;
        int n2 = word2.length() ;

        if( n1 == 0 )
            return word2 ;

        if( n2 == 0 )
            return word1 ; 

        int i = 0 ;
        int j = 0 ;
        string ans ;

        bool takeFirst = true ;

        while( i<n1 && j<n2 ){
            if( takeFirst == true ){
                ans += word1[i] ;
                i++ ;
                takeFirst = false ;
            }
            else{
                ans += word2[j] ;
                j++ ;
                takeFirst = true ;
            }
        }

        while( i<n1 ){
            ans += word1[i] ;
            i++ ;
        }

        while( j<n2 ){
            ans += word2[j] ;
            j++ ;
        }    

        return ans ;
    }
};