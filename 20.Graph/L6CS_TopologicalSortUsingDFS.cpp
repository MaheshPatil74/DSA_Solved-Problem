topological sort can only valid when graph is "directed acyclic graph"
//  Approach 1 ==>> using DFS
// TC = O( N+E ) and SC = O( N+E )

#include <bits/stdc++.h> 

void topoSort(int node ,vector<bool>&visited , stack<int> &s , unordered_map< int , list<int> > &adj ){
    
    visited[node] = 1 ;
    for( auto neighbour : adj[node] ){
        if( !visited[neighbour] ){
            topoSort( neighbour , visited , s , adj ) ;
        }
    }
    // most imp step
    s.push(node) ;
}

vector<int> topologicalSort(vector<vector<int>> &edges, int v, int e)  {
    // Write your code here

    // create adjacency list 
    unordered_map< int , list<int> > adj ;
    for( int i = 0 ; i<e ; i++ ){
        int u = edges[i][0] ;
        int v = edges[i][1] ;

        adj[u].push_back(v) ;
    }

    // call dfs topological sort util function for all component
    vector< bool > visited(v) ;
    stack<int> s ;

    for( int i = 0 ; i<v ; i++ ){
        if( !visited[i] ){
            topoSort( i , visited , s , adj ) ;
        }
    }

    vector<int> ans ;
    while( !s.empty() ){
        ans.push_back( s.top() );
        s.pop() ;
    }
    return ans ;
}