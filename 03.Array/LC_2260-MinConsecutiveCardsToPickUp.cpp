// Approach 1 : Using Map
// TC : O(N) , SC : O(N)
class Solution {
public:
    int minimumCardPickup(vector<int>& cards) {
        unordered_map<int,int> mp ;
        int mini = INT_MAX ;
        for( int i = 0 ; i<cards.size() ; i++ ){
            if( mp.count( cards[i] ) )
                mini = min( mini , i-mp[cards[i]]+1 ) ;

            mp[ cards[i] ] = i ;
        } 
        return (mini == INT_MAX) ? -1 : mini ;
    }
};