#include <iostream>
#include <math.h>
using namespace std ;
//LinearSearch
bool LinearSearch( int arr[] , int size , int key ){
    for(int i = 0 ; i <= size ; i++ ){
        if( arr[i] == key ){
            return 1 ;
        }
    }
    return 0 ;
}

int main() {
    int array[5] = { 5, 4 , 3 , 2 , 1 } ;
    
    int element ;
    cout<<"Enter The Element To be Search : ";
    cin>>element ;
    
    if( LinearSearch( array , 5 , element ) ){
        cout<<element<<" is Present in Array ." ;
    }else{
        cout<<element<<" is Absent in Array ." ;
    }
    
    return 0;
}

/*
//My Code : 
#include <iostream>
using namespace std ;

int LinearSearch(int arr[] , int size , int key){
    int sum = 0 ;
    for(int i = 0 ; i<size ; i++){
        if( arr[i] == key ){
            return i ;
        }
    }   
    return -1 ;
}

int main() {
    int array[10] = { 10,9,8,7,6,5,4,3,2,1} ;
    int key ;
    cout<<"Enter The Element To be Search : ";
    cin>>key ;
    
    int ans = LinearSearch(array , 10 , key ) ;
    
    if(ans != -1){
        cout<<"Element is Present in Array at Index : "<<ans<<endl ;
    }else{
        cout<<"Element Is Absent In Array .";
    }
    
    return 0;
}
*/