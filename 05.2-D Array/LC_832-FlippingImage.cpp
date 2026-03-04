// Approach 2 : More Optimal 
// TC : O(N*N) , SC : O(1)
class Solution {
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        int n = image.size() ;
        for( int i = 0 ; i<n ; i++ ){
            int left = 0 ;
            int right = n-1 ;
            while( left < right ){
                image[i][left] ^= 1 ;
                image[i][right] ^= 1 ; 
                swap( image[i][left++] , image[i][right--] );
            }
            if( left == right )
                image[i][left] ^= 1 ;
        }
        return image ;
    }
};


// Approach 1 
// TC : O(N*N) , SC : O(1)
class Solution {
private :
    void flipHorizontallyAndInvert(vector<vector<int>>& image){
        int n = image.size() ;
        
        // horizontallyFlip and Invert 
        for( int i = 0 ; i<n ; i++ ){
            int left = 0 ;
            int right = n-1 ;
            while( left < right ){
                image[i][left] = (image[i][left] == 0) ? 1 : 0 ;
                image[i][right] = (image[i][right] == 0) ? 1 : 0 ;

                swap( image[i][left++] , image[i][right--] );
            }
            if( left == right )
                image[i][left] = (image[i][left] == 0) ? 1 : 0 ;
        }
    }
public:
    vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) {
        flipHorizontallyAndInvert(image);
        return image ;
    }
};