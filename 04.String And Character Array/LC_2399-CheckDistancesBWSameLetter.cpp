/*
LeetCode 2399: Check Distances Between Same Letters.

Store the first index of each character, and when it appears again, check if the number of characters between the two occurrences equals the given distance; if any mismatch occurs return false, otherwise true

Time Complexity: O(n)
Space Complexity: O(1)
*/
class Solution {
public:
    bool checkDistances(string s, vector<int>& distance) {
        vector<int> track(26,-1) ;

        for( int i = 0 ; i<s.length() ; i++ ){
            int idx = s[i]-'a' ;
            if( track[idx] == -1 )   //first time occur
                track[idx] = i ;
            else{
                int currIndex = i ;
                int prevIndex = track[idx] ;
                int diff = currIndex - prevIndex - 1 ;
                if( diff != distance[idx] )
                    return false ;
            }
        }
        return true ;
    }
};