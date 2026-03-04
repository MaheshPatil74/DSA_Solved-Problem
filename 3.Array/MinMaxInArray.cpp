#include <iostream>
using namespace std ;

void minMax(int arr[],int size){
    int max = arr[0] ;
    int min = arr[0] ;
    
    for(int i = 0 ; i<size ; i++ ){
        if( max < arr[i] ){
            max = arr[i] ;
        }
        if( min > arr[i] ){
            min = arr[i] ;
        }
    }
    
    cout<<"Maximum Element in Array : "<<max<<endl ;
    cout<<"Minimum Element in Array : "<<min<<endl ;
}

int main() {
    int num ; 
    cout<<"Enter The Size of Array : ";
    cin>>num ;
    
    int array[100] ;
    cout<<"Enter The Element : ";
    for( int i = 0 ; i<num ; i++ ){
        cin>>array[i];
    }
    
    minMax(array,num);
    return 0;
}  