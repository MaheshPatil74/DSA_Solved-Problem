
// Linear Time and space complexity

#include<unordered_map>
#include<queue>
#include<list>
#include<set>

void bfs(vector<vector<int>> &adj ,unordered_map< int , bool > &visited , vector<int> &ans , int node ){
    queue<int> q ;
    q.push(node) ;
    visited[node] = 1 ;

    while( !q.empty() ){
        int frontNode = q.front() ;
        q.pop() ;

        // store frontNode into ans 
        ans.push_back(frontNode) ;

        // traverse all neighbour of frontNode
        for( auto i : adj[frontNode] ){
            if( !visited[i] ){
                q.push(i) ;
                visited[i] = 1 ;
            }
        }
    }
}

vector<int> bfsTraversal(int n, vector<vector<int>> &adj){
    // Write your code here.

    vector<int> ans ;
    unordered_map< int , bool > visited ;

    // traverse all component of graph

    // For disconnectd component of graph is present
    // for(int i = 0 ; i<n ; i++ ){
    //     if( !visited[i] ){
    //         bfs(adj , visited , ans , i ) ;
    //     }
    // }

    // For disconnectd component of graph is Absent
    bfs(adj , visited , ans , 0 ) ; 

    return ans ;
}