// TC : O(N*LogN) , SC : O(1)
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int n = people.size() ;
        sort( people.begin() , people.end() );
        int boats = 0 ;
        int i = 0 ;
        int j = n-1 ;

        while( i<=j ){
            if( people[i] + people[j] <= limit )
                i++ ;   // light person used

            j-- ;   // heavy always used
            boats++ ;
        }
        return boats ;
    }
};