#include<iostream>
using namespace std ;

#include <bits/stdc++.h>

vector<vector<int>> pairSum(vector<int> &arr, int s){
   // Write your code here.
   vector<vector<int>> ans ;
   int i = 0 ;
   int j = arr.size() - 1 ;

   while( i<j ){
      int sum = arr[i] + arr[j] ;

      if( sum == s ){
         ans.push_back( { arr[i] , arr[j] } ) ;
         i++ ;
         j-- ;
      }
      else if( sum < s ){
         i++ ;
      }
      else{
         j-- ;
      }
   }
   return ans ;
}

//Approach 1 : My Approach
void PairSum2(int arr[] , int size , int sum ){
    for( int i = 0 ; i<size ; i++ )
        for( int j = i+1 ; j<size ; j++)
            if( arr[i]+arr[j] == sum )
                cout<<arr[i]<<" "<<arr[j]<<" "<<endl;
}

int main(){
    int array[5] = { 1 , 2 , 3 , 4 , 5 } ; 
    PairSum1(array , 5 , 5) ;
    PairSum2(array , 5 , 5) ;
    return 0 ;
}