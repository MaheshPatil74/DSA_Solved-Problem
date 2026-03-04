// Approach 1 ==>> in lecture 8

// Approach 2 ==>> using BFS or Kahn's algo  // TC = O( N+E ) and SC = O( N+E )
// means approach of kahn's algo we used here
// that is if valid topological sort are there then graph is acyclic hence cycle absent

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges){
    // create adjacency list 
    unordered_map< int , list<int> > adj ;
    for( int i = 0 ; i<edges.size() ; i++ ){
        int u = edges[i].first - 1 ;
        int v = edges[i].second - 1 ;
        // in above 2 lines we substrect 1 because in these que. nodes  start from 1

        adj[u].push_back(v) ;
    }

    // find all indegrees
    vector<int> inDegree(n) ;
    for( auto i : adj ){
        for( auto j : i.second ){
            inDegree[j]++ ;
        } 
    }

    // 0 degree walo ko push karo
    queue<int> q ;
    for( int i = 0 ; i<n ; i++ ){
        if( inDegree[i] == 0 ){
            q.push(i) ;
        }
    }

    // do bfs

    int count = 0 ;
    while( !q.empty() ){
        int front = q.front() ;
        q.pop() ;

        // increment count
        count++ ;

        // neighbour indegree update
        for( auto neighbour : adj[front] ){
            inDegree[neighbour]-- ;
            if( inDegree[neighbour] == 0 ){
                q.push(neighbour) ;
            }
        }
    }
    if( count == n ){
        // means valid topological sort mans cycle absent
        return false ;
    }
    else{
        // else cycle present
        return true ;
    }    
}