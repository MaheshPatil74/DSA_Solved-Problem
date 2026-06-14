// TC : O( N*LogN ) , SC : O(1)
class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size() ;

        if( n < 2 )
            return cost[0] ;

        sort( cost.begin() , cost.end() ) ;
        int minCost = 0 ;

        int idx = n-1 ;

        while( idx > -1 ){
            minCost += cost[idx--] ;
            if( idx > -1 )
                minCost += cost[idx] ;
            idx -= 2 ;
        }

        return minCost ;
    }
};