#include<iostream>
using namespace std ;

bool isEven( int n ){
     //odd
     if( n&1 )
        return 0 ;
    //even
    return 1 ;
}

int main(){
    int num ;
    cout<<"Enter Number : ";
    cin>>num ;
    
    if(isEven(num)){
        cout<<num<<" is Even Number."<<endl;
    }
    else{
        cout<<num<<" is Odd Number."<<endl;
    }
    
    return 0 ;
}