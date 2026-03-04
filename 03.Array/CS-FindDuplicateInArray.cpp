#include<iostream>
using namespace std ;

int findDuplicate(int arr[] , int size ){
    int ans = 0 ;

    //performing XOR with all Array Element 
    for(int i = 0 ; i<size ; i++ ){
        ans = ans ^ arr[i] ;
    }

    //performing XOR [1,n-1]
    for(int i = 1 ; i<size ; i++ ){
        ans = ans ^ i ;
    }
    return ans ;
}

int main(){
    int array[5] = { 1 , 2 , 4 , 3 , 4 } ;
    cout<<"Duplicate Element is : "<<findDuplicate(array , 5) ;
}

// Approach 2 
int findDuplicate(vector<int> &arr) 
{
    // Write your code here
    int n = arr.size() ;
    int sum1 = 0 ; 
    int sum2 = ((n-1) * n)/2 ;

    for(int i = 0 ; i<n ; i++ ){
        sum1 += arr[i] ;
    } 

    return sum1 - sum2 ;
}
