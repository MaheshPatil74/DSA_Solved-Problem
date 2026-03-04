#include <iostream>
#include<vector>
using namespace std ;

void PrintArray(vector<int> arr  ){
    for(int i = 0 ; i<arr.size() ; i++ ){
        cout<<arr[i]<<" ";
    }
    cout<<endl ;
}

vector<int> ReverseArray( vector<int> arr, int m  ){
    
    int start = m+1 ;
    int end = arr.size() - 1 ;
    
    while(start<=end){
        swap(arr[start],arr[end]) ;
        start++ ;
        end-- ;
    }
    return arr ;
}

int main() {
    vector<int> v = {1 ,2 ,3 ,4 ,5 ,6,7} ;

    PrintArray(v) ;

    vector<int> ans = ReverseArray(v,3) ;
    
    PrintArray(ans) ;
    
    return 0;
}