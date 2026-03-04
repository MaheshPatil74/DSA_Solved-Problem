// We Already have a algorith to find a shortest path i.e. ==>> DIJKSHTRA'S Algo
// But that algo can not applicable on negative weights
// So we used a BellMan Ford Algo

// 1) used to find Negative Cycle in Graph
// 2) if Negative Cycle can't present then we find shortest path using bellMan Ford Algo

// In sir code
// TC = O( N*M )

int bellmonFord(int n, int m, int src, int dest, vector<vector<int>> &edges) {
    // Write your code here.
    vector<int> dist(n+1 , 1e9);
    dist[src] = 0;

    // (n-1) times
    for( int i = 1 ; i<=n ; i++ ){
        // traverse on edges list
        for( int j = 0 ; j<m ; j++ ){
            int u = edges[j][0] ;
            int v = edges[j][1] ;
            int wt = edges[j][2] ;

            if( !dist[u] != 1e9 && (dist[u] + wt )< dist[v] ){
                dist[v] = dist[u] + wt ;
            }
        }
    }

    // check for negative cycle
    // not necessary for these code ==>> only for to understand negative cycle code
    bool flag = 0 ;
    for( int j = 0 ; j<m ; j++ ){
        int u = edges[j][0] ;
        int v = edges[j][1] ;
        int wt = edges[j][2] ;

        if( !dist[u] != 1e9 && (dist[u] + wt )< dist[v] ){
            flag = 1 ;
        }
    }

    if( flag == 0 )
        return dist[dest] ;

    return -1 ;
}

// my Code Studio Code
vector<int> bellmonFord(int n, int m, int src, vector<vector<int>> &edges) {
    // Write your code here.
}