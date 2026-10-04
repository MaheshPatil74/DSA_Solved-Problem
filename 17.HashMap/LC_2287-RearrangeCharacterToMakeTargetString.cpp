// Approach 2 : OWN ==>> Same as 1 only change hashmap timto vector to reduced SC
// TC : O(N+M) , SC : O(1)
class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        vector<int> sfreq(26,0) ;
        for( char ch : s )
            sfreq[ch-'a']++ ;

        vector<int> tfreq(26,0) ;
        for( char ch : target )
            tfreq[ch-'a']++ ;

        int mini = INT_MAX ;
        for( int i = 0 ; i<26 ; i++ )
            if( tfreq[i] > 0 )
                mini = min( mini , sfreq[i]/tfreq[i] ) ;

        return mini ;
    }
};

// Approach 1 : OWN
// TC : O(N+M) , SC : O(N+M)
class Solution {
public:
    int func( unordered_map<char,int> &have , unordered_map<char,int> &need ){
        int mini = INT_MAX ;
        for( auto i : need ){
            char ch  = i.first ;
            int fhave = have[ch] ;
            int fneed = need[ch] ;
            int count = fhave/fneed ;
            mini = min( mini , count ) ;
        }
        return mini ;
    }

    int rearrangeCharacters(string s, string target) {
        unordered_map<char,int> have ;
        for( char ch : s )
            have[ch]++ ;

        unordered_map<char,int> need ;
        for( char ch : target )
            need[ch]++ ;

        return func( have , need ) ;
    }
};