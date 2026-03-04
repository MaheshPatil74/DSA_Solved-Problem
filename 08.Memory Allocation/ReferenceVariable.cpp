#include<iostream>
using namespace std ;

int & func( int a ){       
    //To Much BAD practice --> retrun about local variable
    //because local variable are free when its scope is ended
    // so as function return reference or address , we dont know address of which it return which is risky  
    int num = a ;
    int & ans = num ;
    return ans ;
}

int * fun( int a ){
    int num = a ;
    int & ans = num ;
    return ans ;
}

void update2( int & n ){          //Function Using Call by Reference
    //here , n is reference variable
    n++ ;
}

void update1( int n ){          //Function Using Call by Value
    n++ ;
}

int main(){

/*
    int i = 5 ;
    
    //create a Reference variable
    // Reference Variable --> Same Memory with Different name

    int & j = i ;

    cout<< i << endl ;
    i++ ;
    cout<< i << endl ;
    j++ ;
    cout<< i << endl ;
*/

    int n = 5 ;
    cout<<" Before n : "<< n <<endl ;
    update1( n ) ;  //Call by Value Function
    cout<<" After n : "<< n <<endl ;

    cout<<endl ;

    cout<<" Before n : "<< n <<endl ;
    update2( n ) ;  //Call by Reference Function
    cout<<" After n : "<< n <<endl ;

    fun(n) ;
    cout<<endl ;
    func(n) ;

    return 0 ;
}