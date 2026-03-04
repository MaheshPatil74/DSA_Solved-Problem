#include<iostream>
using namespace std ;

int main(){
    int num , sum = 0 ;

    cout<<"Enter The Number : ";
    cin>>num ;

    int i = 1 ;
    while(i<=num){
        sum += i ;
        i++ ;
    }
    cout<<"Sum Is "<<sum ;

    return 0 ;


}