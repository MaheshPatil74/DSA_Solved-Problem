// Approach 2 : Optimal( Sorting + Greedy )
// TC : O(N*LogN) , SC : O(1)
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {

        sort( intervals.begin() , intervals.end() , [](vector<int>&a , vector<int>&b){
            if( a[0] == b[0] )
                return a[1]>b[1] ;
            return a[0] < b[0] ;
        });
        
        int ans = 0 ;
        int maxEnd = INT_MIN ;
        for( auto &it : intervals )
            if( it[1] > maxEnd ){
                ans++ ;
                maxEnd = it[1] ;
            }

        return ans ;
    }
};

// Approach 1 : brute force
// TC : O(N*N) , SC : O(1)
class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size() ;
        int count = n ;
        for( int i = 0 ; i<n ; i++ )
            for( int j = 0 ; j<n ; j++ ){
                if( i == j )
                    continue ;
                
                if( (intervals[i][0] >= intervals[j][0]) && (intervals[i][1] <= intervals[j][1]) ){
                    count-- ;
                    break ;
                }
            }

        return count ;
    }
};