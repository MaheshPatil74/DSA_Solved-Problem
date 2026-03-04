#include<iostream>
#include<map>
#include<unordered_map>
using namespace std ;

// in map : sequence of entering is maintain or order is maintain
// in unordered map : order  not preserved

int main(){

    // all have TC = O(1)

    // creation
    unordered_map< string , int > m ;

    // Insertion
    // way 1 
    pair< string , int > p1 = make_pair( "Mahesh" , 1 ) ;
    m.insert(p1) ;

    // way 2
    pair< string , int > p2( "Mayur" , 2 ) ;
    m.insert(p2) ;

    // way 3
    m["Bhushan"] = 3 ;
    cout << m["Bhushan"] <<endl ;

    // updation 
    m["Bhushan"] = 4 ;
    cout << m["Bhushan"] <<endl ;

    // search
    // way 1 : if key exist then give value
    // if key not exist then create a key and assign a value zero('0')
    cout << m["Mahesh"] <<endl ;

    // way 2 : if key exist then give value
    // if key not exist then give abort error
    cout << m.at("Mahesh") <<endl ;
    
    // search for unknown key
    // // way 1 
    // cout << m.at("Mahesh") <<endl ; //give error as entry not exist
    // cout << m["king"] <<endl ; //create new entry and assign value 0
    
    // // way 2
    // cout << m["king"] <<endl ; //create new entry and assign value 0
    // cout << m.at("Mahesh") <<endl ; //give output as above line make new entry ==> 0

    // size
    cout<< m.size() <<endl ;

    // count 
    // if key absent return 0 else return 1 
    cout<< m.count("Mayur") <<endl ; // 1
    cout<< m.count("Queen") <<endl ; // 0

    // erase
    m.erase("Mayur") ;
    cout<< m.size() <<endl ;

    // printing or accessing key value pair of map
    // way 1 : using loop
    for( auto i : m ){
        cout<< i.first << " : " << i.second <<endl ;
    }

    // way 2 : using iterator

    unordered_map< string , int > :: iterator it = m.begin() ;
    while( it != m.end() ){
        cout<< it->first << " : " << it->second << endl ;
        it++ ;
    }

    return 0 ;
}