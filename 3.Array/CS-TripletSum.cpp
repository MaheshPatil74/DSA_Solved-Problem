#include<iostream>
using namespace std ;

//Approach 1 : My Approach
void PairSum(int arr[] , int size , int sum ){
    for( int i = 0 ; i<size ; i++ ){
        for( int j = i+1 ; j<size ; j++){
            for( int k = j+1 ; k<size ; k++ ){
                if( arr[i] + arr[j] + arr[k] == sum ){
                    cout<<arr[i]<<" "<<arr[j]<<" "<<arr[k]<<endl;
                }
            }
        }
    }
}

int main(){
    
    int array[8] = { 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 } ; 
    
    PairSum(array , 8 , 10) ;
    
    return 0 ;
}