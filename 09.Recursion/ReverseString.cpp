#include<iostream>
using namespace std ;
/*
// Using two Pointer Approach ==>
void Reverse1(string & str , int i , int j ){
    //Base case  
    if(i>j)     return ;

    swap(str[i++] , str[j--]);
    Reverse1(str,i,j) ;
}
*/

// Using Single Pointer Approach ==>
void Reverse2(string & str , int i  ){
    int n = str.length() ;
    if( i > (n-i-1) )
        return ;

    swap(str[i] , str[n-i-1]);
    i++ ;
    Reverse2(str,i) ;
}

int main(){

    string name = "MaheshP" ;

    cout<<name<<endl;

    // Reverse1( name , 0 , name.length()-1 ) ;
    Reverse2( name , 0 ) ;


    cout<<name<<endl;
    return 0 ;
}