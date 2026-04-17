// Approach 3 : Two pointer to trackk left max and right max 
// TC : O(N) , SC : O(1)
class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size() - 1;
        int leftMax = 0, rightMax = 0;
        int total = 0;

        while (left < right) {
            if (height[left] < height[right]) {
                if (height[left] >= leftMax)
                    leftMax = height[left];
                else
                    total += leftMax - height[left];
                left++;
            } else {
                if (height[right] >= rightMax)
                    rightMax = height[right];
                else
                    total += rightMax - height[right];
                right--;
            }
        }
        return total;
    }
};

// Approach 2 : Right and left maximum array
// TC : O(N) , SC : O(N)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size() ;
        vector<int> left(n) , right(n) ;
        left[0] = height[0] ;
        right[n-1] = height[n-1] ;
        for( int i = 1 ; i<n ; i++ ){
            left[i] = max( left[i-1] , height[i] );
            right[n-i-1] = max( right[n-i] , height[n-i-1] ) ;
        }

        int total = 0 ;
        for( int i = 0 ; i<n ; i++ )
            total += min( left[i] , right[i] ) - height[i] ;

        return total ;
    }
};

// Approach 1 : Bruite force
// TC : O(N*N) , SC : O(1)
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size() ;
        int total = 0 ;
        for( int i = 0 ; i<n ; i++ ){
            int leftmax = 0 , rightmax = 0 ;
            for( int j = 0 ; j<=i ; j++ )
                leftmax = max( leftmax , height[j] ) ;
            for( int j = i ; j<n ; j++ )
                rightmax = max( rightmax , height[j] ) ;
            total += min(leftmax,rightmax) - height[i] ;
        }
        return total ;
    }
};