#include<iostream>
using namespace std ;

void compare( int a ){
    if(a>0){
        cout<<a<<" is Positive. ";
    }
    else if(a<0){
        cout<<a<<" is Negative. ";
    }
    else{
        cout<<" Zero ";
    }
}

int main(){
    int num ;

    cout<<"Enter The Number : ";
    cin>>num ;

    compare(num);
    return 0 ;


}