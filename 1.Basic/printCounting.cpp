#include<iostream>
using namespace std ;

void printCounting(int n){
    for(int i = 1 ; i<=n ; i++){
        cout<<i<<endl;
    }
}

int main(){
    int num ;
    cout<<"Enter The Number : ";
    cin>>num ;
    printCounting(num );
    return 0 ;
}