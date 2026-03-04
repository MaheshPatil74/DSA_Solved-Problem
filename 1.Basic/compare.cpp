#include<iostream>
using namespace std ;

void compare(int a , int b){
    if(a>b){
        cout<<a<<" is Larger. ";
    }
    else if(a<b){
        cout<<b<<" is Larger. ";
    }
    else{
        cout<<"Both are Equal. ";
    }
}

int main(){
    int num1 , num2 ;

    cout<<"Enter The First Number : ";
    cin>>num1 ;
    cout<<"Enter The Second Number : ";
    cin>>num2 ;

    compare(num1,num2);
    return 0 ;


}