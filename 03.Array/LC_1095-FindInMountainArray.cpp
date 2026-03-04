/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

// Approach 2 : Not Optimal (Linear Search) Not Accepted on Leetcode
// TC: O(n)
// SC: O(1)
class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length() ;

        for( int i = 0 ; i<n ; i++ ){
            int num = mountainArr.get(i) ;
            if( num == target )
                return i ;
        }   
        return -1 ;
    }
};

// Approach 1 : (OWN) (Optimal)Using 3 Binary Searches
//TC: O(log n) + O(log n) + O(log n) = O(log n)
//SC: O(1)
class Solution {
public:
    int findPeakElement(MountainArray &mountainArr){
        int left = 0 ;
        int right = mountainArr.length() - 1 ;

        while( left<right ){
            int mid = left + (right-left)/2 ;

            if( mountainArr.get(mid) < mountainArr.get(mid+1) ){
                left = mid + 1 ;
            }
            else{
                right = mid ;
            }
        }
        return left ; 
    }

    int binarySearchIncrease(MountainArray& mountainArr , int target , int start , int end ){
        int ans = -1 ;
        while( start <= end ){
            int mid = start + (end-start)/2 ;
            int num = mountainArr.get(mid) ;
            if( num == target ){
                ans = mid ;
                end = mid - 1 ;
            }
            else if( num < target ){
                start = mid+1 ;
            }
            else{
                end = mid-1 ;
            }
        } 
        return ans ;
    }

    int binarySearchDecrease(MountainArray& mountainArr , int target , int start , int end ){
        int ans = -1 ;
        while( start <= end ){
            int mid = start + (end-start)/2 ;
            int num = mountainArr.get(mid) ;
            if( num == target ){
                ans = mid ;
                end = mid - 1 ;
            }
            else if( num > target ){
                start = mid+1 ;
            }
            else{
                end = mid-1 ;
            }
        } 
        return ans ;
    }

    int findInMountainArray(int target, MountainArray &mountainArr) {
        int peakIndex = findPeakElement( mountainArr ) ;
        int n = mountainArr.length() ;
        int first = binarySearchIncrease(mountainArr , target , 0 , peakIndex );
        int last = binarySearchDecrease(mountainArr , target , peakIndex+1 , n-1 );

        if( first != -1 )
            return first ;
        if( last != -1 )
            return last ;
        return -1 ;
    }
};