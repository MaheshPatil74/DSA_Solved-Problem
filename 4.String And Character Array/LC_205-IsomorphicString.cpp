// Approach 2 : using vector faster than map
// TC : O(N) , SC : O(N)==O(1) // fixed size 256 at most
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.length() != t.length())
            return false;

        vector<int> mapST(256, -1);
        vector<int> mapTS(256, -1);

        for (int i = 0; i < s.length(); i++) {
            char c1 = s[i];
            char c2 = t[i];
            if (mapST[c1] == -1 && mapTS[c2] == -1) {
                mapST[c1] = c2;
                mapTS[c2] = c1;
            }
            else if( (mapST[c1] != c2) || (mapTS[c2] != c1) ) 
                return false;
        }
        return true;
    }
};


// Approach 1 : using map
// TC : O(N) , SC : O(N)==O(1) // fixed size 256 at most
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if( s.length() != t.length() )
            return false ;

        unordered_map<char , char> mapST , mapTS ;
        for( int i = 0 ; i<s.length() ; i++ ){
            char c1 = s[i] ;
            char c2 = t[i] ;
            if( (mapST.count(c1) && mapST[c1] != c2) || 
                (mapTS.count(c2) && mapTS[c2] != c1)  )
                return false ;
            mapST[c1] = c2 ;
            mapTS[c2] = c1 ;
        }
        return true ;
    }
};