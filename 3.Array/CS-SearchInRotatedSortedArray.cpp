// Approach 2 ==> Without Using Pivot Element
int search(vector<int>& arr, int n, int k)
{
    // Write your code here.
    // Return the position of K in ARR else return -1.
    int left = 0 ; 
    int right = n-1 ;
    int mid = left + (right-left)/2 ;

    while( left<=right ){
        if( arr[mid] == k )
            return mid ;

        // Left half sorted
        if( arr[left] <= arr[mid] ){
            if( arr[left] <= k && k<arr[mid])
                right = mid-1 ;
            else    
                left = mid+1 ;
        }
        // Right half sorted
        else{
            if( arr[mid] < k && k<=arr[right])
                left = mid+1 ;
            else    
                right = mid-1 ;
        }

        mid = left + (right-left)/2 ;
    }
    return -1 ;
}


// Approach 1 ==> Using Pivot Element
#include <iostream>
using namespace std ;

int getpivot(int arr[] , int size ){
    int start = 0 ;
    int end = size - 1 ;
    int mid = start + (end-start)/2 ;
    while( start < end ){
        if( arr[mid]>= arr[0] ){
            start = mid + 1 ;
        }else{
            end = mid ;
        }
        mid = start + (end-start)/2 ;
    }
    return start ;
}
int BinarySearch(int arr[] , int s , int e , int key){
    int left = s ;
    int right = e ;
    
    while( left<=right ){
        int mid = left + (( right - left )/2) ;
        
        if( arr[mid] == key ){
            return mid ;
        }
        else if( arr[mid]<key ){
            left = mid + 1 ;
        }
        else{
            right = mid - 1 ;
        }
    }
    return -1 ;
}

int findPosition(int arr[] , int n , int key){
    int pivot = getpivot(arr , n );
    
    if( key>=arr[pivot] && key<=arr[n-1] ){
        return BinarySearch(arr , pivot , n-1 , key ) ; 
    }
    else{
        return BinarySearch(arr , 0 , pivot-1 , key ) ; 
    }
}

int main() {

    int array[5] = {3,4, 5, 1, 2 } ;
    int number ;
    cout<<"Enter The Number To Be Search : ";
    cin>>number ;
    
    cout<<"Element is Found At Index : "<<findPosition(array , 5 , number)<<endl;
    return 0;
}