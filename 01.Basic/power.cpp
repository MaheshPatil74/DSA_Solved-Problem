#include<iostream>
using namespace std ;

int power(int a , int b ){
    int ans = 1 ;
    for(int i=1 ; i<=b ;i++){
        ans = ans * a ;
    }
    return ans ;
}

int main(){
    int num1 , num2 ;
    cout<<"Enter First Number : ";
    cin>>num1 ;
    cout<<"Enter Second Number : ";
    cin>>num2;
    
    cout<<"Power Answer : "<<power(num1,num2)<<endl;
    return 0 ;
}