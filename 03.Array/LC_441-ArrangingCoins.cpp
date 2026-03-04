// Approach 2 : Binary Search
// Time Complexity: O(log n)
// Space Complexity: O(1)
class Solution {
public:
    int arrangeCoins(int n) {
        int left = 1 ;
        int right = n ;
        int res = 0 ;

        while( left<=right ){
            long long int mid = left+(right-left)/2 ;
            long long coins = (mid * (mid+1))/2 ;
            if( coins > n )
                right = mid-1 ;
            else{
                left = mid+1 ;
                res = (res>mid) ? res : mid ;
            }
        }
        return res ;
    }
};

// Approach 1 : Iterative Subtraction(Brute Force Approach)
// Time Complexity: O(sqrt(n))
// Space Complexity: O(1)
class Solution {
public:
    int arrangeCoins(int n) {
        int row = 0 ;
        while( n>row ){
            row++ ;
            n = n-row ;
        }
        return row ;
    }
};