#include<iostream>
using namespace std ;


// Using Tail Recursion
// Tail Recursion ==>> Base Case --> Processing --> Recursive Relation
void Counting1( int n ){
    //Base case
    if(n==0){
        return ;
    }

    // Processing
    cout<<n<<" ";

    //Recursive Relation
    Counting1(n-1) ;
}

// Using Head Recursion
// Head Recursion ==>> Base Case --> Recursive Relation --> Processing 
void Counting2( int n ){
    //Base case
    if(n==0){
        return ;
    }

    //Recursive Relation
    Counting2(n-1) ;
    
    // Processing
    cout<<n<<" ";
}

int main(){
    int n ;
    cout<<"Enter The Value : ";
    cin>>n ;

    cout<<"Answer : ";
    // Counting1(n) ;
    Counting2(n) ;

    return 0 ;
}