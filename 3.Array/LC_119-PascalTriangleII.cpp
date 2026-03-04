// Approach 3: Using Single Vector in Reverse Order ==> Updating the current row in reverse order to avoid overwriting values needed for calculation
// Time Complexity: O(rowIndex^2)
// Space Complexity: O(rowIndex)
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<int> prevRow(rowIndex+1 , 1) ;
        for( int i = 1 ; i<rowIndex ; i++ )
            for( int j = i ; j>0 ;j-- )
                prevRow[j] = prevRow[j-1] + prevRow[j] ;
        return prevRow ;
    }
};

// Approach 2: Using Single Vector ==> Optimized approach to use only one vector to store the current row
// Time Complexity: O(rowIndex^2)
// Space Complexity: O(rowIndex)
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<int> prevRow ;
        for( int i = 0 ; i<=rowIndex ; i++ ){
            vector<int> temp(i+1 , 1 );
            for( int j = 1 ; j<i ;j++ )
                temp[j] = prevRow[j-1] + prevRow[j] ;
            prevRow = temp ;
        }
        return prevRow ;
    }
};

// Approach 1: Using 2D Vector ==> Building the entire Pascal's Triangle up to the given rowIndex and returning the desired row
// Time Complexity: O(rowIndex^2)
// Space Complexity: O(rowIndex^2)
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        
        vector<vector<int>> ans(rowIndex+1) ;
        for( int i = 0 ; i<=rowIndex ; i++ ){
            vector<int> temp(i+1 , 1 );
            for( int j = 1 ; j<i ;j++ )
                temp[j] = ans[i-1][j-1] + ans[i-1][j] ;
            ans[i] = temp ;
        }
        return ans[rowIndex] ;
    }
};