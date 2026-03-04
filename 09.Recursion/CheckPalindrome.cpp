#include<iostream>
using namespace std ;

/*
// Using two Pointer Approach ==>
bool CheckPalindrome1( string str , int i , int j ){
    if(i>j) 
        return true ;

    if( str[i] != str[j] )
        return false ;
    else
        CheckPalindrome1(str , i+1 ,j-1 );
}
*/

/*
// Using Single Pointer Approach ==>
bool CheckPalindrome2( string str , int i ){
    int n = str.length() ;

    // base case 
    if( i > (n-i-1) ){
        return true ;
    }

    if( str[i] != str[n-i-1] ){
        return false ;
    }
    else{
        CheckPalindrome2(str , i+1 );
    }
}
*/

int main(){
    string name = "NayaN" ;

    // bool ans = CheckPalindrome1( name , 0 , name.length()-1 ) ;
    bool ans = CheckPalindrome2( name , 0 ) ;
    if(ans){
        cout<<"Given String is Palindrome ." ;
    }
    else{
        cout<<"Given String is Not Palindrome ." ;
    }

    return 0 ;
}