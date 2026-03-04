#include<iostream>
using namespace std ;

void reachHome( int src , int dest ){

    cout<<"Src at : "<<src<<" Dest at : "<<dest<<endl ;

    //Base case
    if( src == dest ){
        cout<<"Reached Destination . "<<endl ;
        return ;
    }

    // Processing
    src++ ;

    //Recursive Relation
    reachHome(src,dest) ;
}

int main(){
    int src = 1 ;
    int dest = 10 ;

    cout<<endl ;

    reachHome(src , dest) ;

    return 0 ;
}