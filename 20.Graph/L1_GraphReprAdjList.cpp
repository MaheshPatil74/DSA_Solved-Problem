#include<iostream>
#include<unordered_map>
#include<list>
using namespace std ;

template < typename T >

class graph{
  public :
    unordered_map< T , list<T> > adj ;

    void addEdge( T u , T v , bool direction ){
        // direction = 0 ==>> undirected
        // direction = 1 ==>> directed

        // create an edge from u to v
        adj[u].push_back(v) ;

        if( direction == 0 )
            adj[v].push_back(u) ;
    }

    void printAdjList(){
        for( auto i : adj ){
            cout<< i.first << " ==>> ";
            for( auto j : i.second){
                cout<< j << ", ";
            }
            cout<<endl ;
        }
    }
};

int main(){
    int n ;
    cout<<"Enter The Number of Node : ";
    cin>> n ;

    int m ;
    cout<< "Enter The Number of Edges : ";
    cin>> m ;

    graph<int> g ;
    for( int i = 0 ; i<m ; i++ ){
        cout<< "Enter The Edge " << i+1 << " : ";
        int u , v ;
        cin>> u >> v ;
        g.addEdge(u , v , 0 ) ;
    }
    g.printAdjList() ;
}