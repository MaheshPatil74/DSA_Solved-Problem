#include<iostream>
using namespace std ;

inline getMax(int & a , int & b ){
    return (a>b) ? a : b ;
}

//Inline Function -->
// if function body have only single line then used 'Inline' keyword
// if 2 or 3 line then may be
//  >3 line then can not used inline
// before compilation --> function call replace by their single line of function  

int main(){

    int p = 1 , q = 2 ;
    int ans = 0 ;

    ans = getMax(p,q) ;
    cout<< ans <<endl ;

    p += 3 ;
    q += 1 ;

    ans = getMax(p,q) ;
    cout<< ans <<endl ;

    return 0 ;
}