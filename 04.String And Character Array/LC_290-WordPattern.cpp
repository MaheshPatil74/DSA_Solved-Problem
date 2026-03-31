// Approach 2 : using two map
// TC : O(N) , SC : O(N)
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> wordArray ;
        int i = 0 ;
        while( i<s.length() ){
            string temp = "" ;
            while( i<s.length() && s[i] != ' ' )
                temp+=s[i++] ;
            wordArray.push_back( temp ) ;
            i++ ;
        }

        if( wordArray.size() != pattern.length() )
            return false ;

        unordered_map<char,string> mp1 ;
        unordered_map<string,char> mp2 ;
        for( int i = 0 ; i<pattern.length() ; i++ ){
            char ch = pattern[i] ;
            string w = wordArray[i] ;

            if( mp1.count(ch) && mp1[ch] != w )
                return false ;

            if( mp2.count(w) && mp2[w] != ch )
                return false ;

            mp1[ch] = w ;
            mp2[w] = ch ;
        }
        return true ;
    }
};

// Approach 1 : Brute force ==>> using single map
// TC : O(N*N) , SC : O(N)
class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> wordArray ;
        int i = 0 ;
        while( i<s.length() ){
            string temp = "" ;
            while( i<s.length() && s[i] != ' ' )
                temp+=s[i++] ;
            wordArray.push_back( temp ) ;
            i++ ;
        }

        if( wordArray.size() != pattern.length() )
            return false ;

        unordered_map<char,string> mp ;
        for( int i = 0 ; i<pattern.length() ; i++ ){
            if( mp.count( pattern[i] ) ){
                if( mp[pattern[i]] != wordArray[i] )
                    return false ;
            }
            else{
                for( auto &it : mp )
                    if( it.second == wordArray[i] )
                        return false ;
                        
                mp[pattern[i]] = wordArray[i] ;
            }
        }
        return true ;
    }
};