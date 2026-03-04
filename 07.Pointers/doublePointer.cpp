#include<iostream>
using namespace std ;

void update( int **p2 ){
    //following operation karne se kuch change hoga ?
    
    //First
    //p2 = p2 + 1 ;         //--> NO

    //Second
    //*p2 = *p2 + 1 ;       //--> Slight Change in p

    //third
    **p2 = **p2 + 1 ;     //--> yes --> value change

}

int main(){

    int i = 5 ;
    int * p = &i ;
    int ** p2 = &p ; 

/*
    cout<< "Printing p : "<< p <<endl ;
    cout<< *p2 <<endl ;

    cout<< i <<endl ;
    cout<< *p <<endl ;
    cout<< **p2 <<endl ;

    cout<< &i <<endl ;
    cout<< p <<endl ;
    cout<< *p2 <<endl ;

    cout<< &p <<endl ;
    cout<< p2 <<endl ;
*/

    cout<<endl<<endl ;
    cout<<" Before "<< i << endl ;
    cout<<" Before "<< p << endl ;
    cout<<" Before "<< p2 << endl ;
    update(p2) ;
    cout<<" After "<< i << endl ;
    cout<<" After "<< p << endl ;
    cout<<" After "<< p2 << endl ;
    cout<<endl<<endl ;


    return 0 ;
}
