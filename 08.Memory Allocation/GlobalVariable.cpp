#include<iostream>
using namespace std ;

int Score = 15 ;        //Global Variable Declaration

//Here We Learn Global Variable So we used it
// But in future we can not used global variable
// as anyone changes value of Global Variable in function which is Risky 
// So instead of Global Variable , we used --> 'Reference Variable; .

void a( int & i ){
    cout<< Score <<" in function a "<< endl ;
    Score++ ;
    cout<< i <<endl ;
    i++ ;
}

void b( int & i ){
    cout<< Score <<" in function b "<< endl ;

    cout<< i <<endl ;
    i++ ;
}


int main(){
    cout<< Score <<" in function main "<< endl ;

    int p = 5 ;
    cout<<"Initial Value of i : "<< p <<endl ;
    a(p) ;
    b(p) ;
    cout<<"Final Value of i : "<< p <<endl ;

    return 0 ;
}