// Approach 2 : Optimal (Binary Search)
// TC : O(LogN) , SC : O(1)
class Solution {
public:
    int firstGreaterEqual(vector<int>& nums , int target ){
        int l = 0 , r = nums.size() ;
        while( l < r ){
            int mid = l + ( r-l)/2 ;
            if( nums[mid] >= target )
                r = mid ;
            else
                l = mid+1 ;   
        }
        return l ;
    }
    int maximumCount(vector<int>& nums) {
        int TotalNegativeNumber = firstGreaterEqual( nums , 0 ) ;
        int posStart = firstGreaterEqual( nums , 1 ) ;
        int TotalPositiveNumber = nums.size() - posStart ;
        return max( TotalNegativeNumber , TotalPositiveNumber );
    }
};

// Approach 1 : Brute Force (Linear Scan)
// TC : O(N) , SC : O(1)
class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int n = nums.size() , neg = 0 , zeroes = 0 ;
        for( int num : nums ){
            if( num >= 1 )
                break ;
            if( num < 0 )
                neg++ ;
            else if( num == 0 )
                zeroes++ ;
        }

        return max( neg , n-neg-zeroes ) ;
    }
};