#include<iostream>
using namespace std ;

int main(){

    int value ;
    cout<<" Enter The Value : ";
    cin>>value ;
    int hundred , fifty , twenty , ten , one ;
    int rem = 0;
    
    hundred = value / 100 ;
    rem = (value%100) ;
    cout<<"Hundred rupee Note : "<<hundred<<endl ;
    
    fifty = rem / 50 ;
    rem = (rem%50) ;
    cout<<"Fifty rupee Note : "<<fifty<<endl ;

    twenty = rem / 20 ;
    rem = (rem%20) ;
    cout<<"Twenty rupee Note : "<<twenty<<endl ;

    ten = rem / 10 ;
    rem = (rem%10) ;
    cout<<"Ten rupee Note : "<<ten<<endl ;
    
    one = rem / 1 ;
    rem = (rem%1) ;
    cout<<"One rupee Note : "<<one<<endl ;
    
    return 0 ;
}