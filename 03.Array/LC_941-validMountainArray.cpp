// Appraoch 


// Approach 1 ==> USing Binary Search to find the peak element and then checking the left and right side of the peak element
// time complexity : O(log n) + O(n)  = O(n)
class Solution {
public:

    int peakMountain( vector<int>& arr ){
        int left = 0 ;
        int right = arr.size() - 1 ;

        int mid = left + (right-left)/2 ;

        while( left < right ){

            if( arr[mid] < arr[mid+1] ){
                left = mid+1 ;
            }
            else{
                right = mid ;
            }
            mid = left + (right-left)/2 ;
        }
        return left ;
    }

    bool validMountainArray(vector<int>& arr) {

        if( arr.size() < 3 )
            return false ;

        int largestIndex = peakMountain(arr) ;

        if( largestIndex == 0 || largestIndex==arr.size()-1 )
            return false ;

        for( int i = 0 ; i<largestIndex ; i++ ){
            if( arr[i] >= arr[i+1])
                return false ;
        }

        for( int i = largestIndex ; i<arr.size()-1 ; i++ ){
            if( arr[i] <= arr[i+1])
                return false ;
        }
        return true ;
    }
};