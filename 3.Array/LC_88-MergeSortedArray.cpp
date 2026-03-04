#include <iostream>
#include<vector>
using namespace std ;

void PrintArray(int arr[] , int n  ){
    for(int i = 0 ; i<n ; i++ ){
        cout<<arr[i]<<" ";
    }
    cout<<endl ;
}
// In original problem we have to merge arr1 and arr2 into arr1
// Time complexity : O(m+n)
// Space complexity : O(1)
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int i = m-1 ;       //i points to the indexes of arr1
        int j = n-1 ;       //j points to the indexes of arr2
        int k = m+n-1 ;     //k points to the indexes of arr3

        while(i>=0 && j>=0){
            if( nums1[i] > nums2[j] )
                nums1[k--] = nums1[i--] ;
            else
                nums1[k--] = nums2[j--] ;
        }
        
        while( j >= 0 )
            nums1[k--] = nums2[j--] ;
    }
};


// This logic is basically merging two sorted arrays into a third array
// space complexity : O(m+n)
void MergeSortedArray(int arr1[] , int m , int arr2[] , int n ,int arr3[] ){
    int i = 0 ;     //i points to the indexes of arr1
    int j = 0 ;     //j points to the indexes of arr2
    int k = 0 ;     //k points to the indexes of arr3

    while(i<m && j<n){
        if( arr1[i] <= arr2[j] ){
            arr3[k] = arr1[i] ;
            i++ ;
            k++ ;
        }
        else{
            arr3[k] = arr2[j] ;
            j++ ;
            k++ ;
        }
    }
    
    while(i<m){
        arr3[k] = arr1[i] ;
        i++ ;
        k++ ;
    }
    
    while(j<n){
        arr3[k] = arr2[j] ;
        j++ ;
        k++ ;
    }
}

int main() {
    int arr1[5] = {1,2,3,7,9} ;
    int arr2[4] = {2,3,4,6} ;
    int arr3[9] = {0} ;

    MergeSortedArray(arr1,5,arr2,4,arr3);

    PrintArray(arr3,9) ;
    
    return 0;
}