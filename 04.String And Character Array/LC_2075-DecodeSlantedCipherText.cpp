// Approach 2 : Optimal without extra space
// Index calculation only
// TC : O(n) , SC : O(1)    
class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int cols = encodedText.size() / rows ;

        string ans = "" ;
        for( int k = 0 ; k<cols ; k++ ){
            int i = 0 , j = k ;
            while( i<rows && j<cols ){
                ans += encodedText[ cols*i + j ] ;
                i++ ;
                j++ ;
            }
        }

        while( !ans.empty() && ans.back() == ' ' )
            ans.pop_back() ;

        return ans ;        
    }
};



// Approach 1 : Brute Force Approach
// Idea => Matrix banakr , Phir har column se diagonal traverse 
// TC : O(n) , SC : O(n)    ==>> Extra matrix space used
class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {
        int cols = encodedText.size() / rows ;

        vector<vector<char>> mat( rows , vector<char>(cols) );
        int idx = 0 ;
        for( int i = 0 ; i<rows ; i++ )
            for( int j = 0 ; j<cols ; j++ )
                mat[i][j] = encodedText[idx++] ;

        string ans = "" ;
        for( int col = 0 ; col<cols ; col++ ){
            int i = 0 , j = col ;
            while( i<rows && j<cols ){
                ans += mat[i][j] ;
                i++ ;
                j++ ;
            }
        }

        while( !ans.empty() && ans.back() == ' ' )
            ans.pop_back() ;

        return ans ;        
    }
};