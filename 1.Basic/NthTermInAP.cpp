#include<iostream>
using namespace std ;

int NthTerm(int n){
    int ans ;
    ans = ( 3 * n ) + 7 ;
    return ans ;
}

int main(){
    int num ; 
    cout<<"Enter The Number : ";
    cin>>num ;

    cout<<num<<"n-th term in AP is : "<<NthTerm(num)<<endl ;
}