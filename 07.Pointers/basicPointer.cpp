#include<iostream>
using namespace std  ;

int main(){

    int num = 5 ;
    cout<<"Value of num : "<<num<<endl ;

    //Address of Operator --> '&'

    cout<<"Address Of num : "<< &num <<endl ;

    int *ptr = &num ;
    cout<<"Address using Pointer : "<< ptr <<endl ;
    cout<<"value using Pointer : "<< *ptr <<endl ;

    double d = 4.3 ;
    double *p2 = &d ;
    cout<<"Address using Pointer : "<< p2 <<endl ;
    cout<<"value using Pointer : "<< *p2 <<endl ;

    cout<<"Size of Integer : "<< sizeof(num) <<endl ;
    cout<<"Size of pointer : "<< sizeof(ptr) <<endl ;
    cout<<"Size of Pointer : "<< sizeof(p2) <<endl ;

    cout<<endl<<endl;
    //pointer to int is created and pointing to some garbage address
    int * n ; //very much bad practice as 'n' pointing to unknown address --> risky
    cout<< *n <<endl ;

    cout<<endl<<endl;

    int i = 5 ;
    int *p = &i ;
    cout<< p <<endl ;
    cout<< *p <<endl ;

    int *q = 0;
    q = &i ;
    cout<< q <<endl ;
    cout<< *q <<endl ;

    cout<<endl<<endl;

    //Operation using pointer
    int number = 5 ;
    int a = number ;
    a++ ;
    cout<<"Value of number become : "<<number<<endl ;

    int * pointer = &number ;
    cout<<"Value of number before : "<<number<<endl ;
    (*pointer)++ ;
    cout<<"Value of number become : "<<number<<endl ;

    cout<<endl<<endl;

    //copying a pointer 
    int * k = pointer ;
    cout<< pointer<< " -- "<< k <<endl ;
    cout<< *pointer<< " -- "<< *k <<endl ;

    cout<<endl <<endl ;

    //Important Concept
    int z = 3 ;
    int *t = &z ;
    //cout<< (*t)++ <<endl ;
    *t = *t + 1 ;
    cout<< *t <<endl ;
    cout<<" t before : "<< t <<endl ;
    t = t+1 ;
    cout<<" t before : "<< t <<endl ;

    return 0 ;
}