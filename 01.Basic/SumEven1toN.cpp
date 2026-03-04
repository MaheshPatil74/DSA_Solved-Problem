#include<iostream>
using namespace std ;

int SumOfEven( int n ){
    int i = 1 , sum = 0 ;
    
    while(i<=n){
        if(i%2 == 0){
            sum += i ;
        }
        i++ ;
    }
    return sum ;
}

int main(){
    int num ;
    cout<<"Enter The Number : ";
    cin>>num ;
    cout<<"Sum Is "<<SumOfEven(num) ;

    return 0 ;
}