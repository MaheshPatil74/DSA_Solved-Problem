#include<iostream>
using namespace std ;

void SayDigit( string arr[] ,int n ){

    //Base case
    if(n==0){
        return ;
    }

    // Processing
    int digit = n%10 ;
    n = n / 10 ;

    // Recursive call ;
    SayDigit(arr,n) ;

    cout<< arr[digit] << " " ;
}

int main(){
    string arr[10] = {"Zero" , "One" , "Two" , "Three" , "Four" , "Five" , "Six" , "Seven" , "Eight" , "Nine"} ;
    cout<<endl ;

    int n ;
    cout<<"Enter The Number : ";
    cin>>n ;

    SayDigit(arr,n) ;
    return 0 ;
}