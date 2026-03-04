#include<iostream>
using namespace std ;

int Factorial( int n ){
    //Base case
    if(n==0){
        return 1 ;
    }

    //Recursive Relation
    return n * Factorial(n-1) ;
}

int main(){
    int n ;
    cout<<"Enter The Value : ";
    cin>>n ;

    cout<<"Answer : "<<Factorial(n)<<endl ;
    return 0 ;
}