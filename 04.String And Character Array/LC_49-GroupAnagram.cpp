// Approach 3 : character frequency key
// TC : O( N . k )   ,   SC : O(N)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > mp ;
        for( string str : strs ){
            vector<int> freq( 26 , 0 );
            for( char c : str )
                freq[ c - 'a' ]++ ;

            string key = "" ;
            for( int i = 0 ; i<26 ; i++ )
                key += '#'+ to_string(freq[i]);
                
            mp[key].push_back( str ) ;
        }

        vector<vector<string>> ans ;
        for( auto it : mp )
            ans.push_back( it.second ) ;

        return ans ;
    }
};



// Approach 2 : using Map And Sorted String
// Anagrams ka sorted string same hota hai 
// TC : O( N . kLogk )   ,   SC : O(N)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string> > mp ;
        for( string str : strs ){
            string temp = str ;
            sort( temp.begin() , temp.end() ) ;
            mp[temp].push_back( str ) ;
        }

        vector<vector<string>> ans ;
        for( auto it : mp )
            ans.push_back( it.second ) ;
            
        return ans ;
    }
};



// Approach 1 : Brute Force
// TC : O( N*N . kLogk )   ,   SC : O(N)
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans ;
        vector<bool> visited(strs.size() , false );

        for( int i = 0 ; i<strs.size() ; i++ ){
            if( visited[i] )
                continue ;

            vector<string> group ;
            string s1 = strs[i] ;
            sort( s1.begin() , s1.end() );
            group.push_back( strs[i] );
            visited[i] = true ;

            for( int j = i+1 ; j<strs.size() ; j++ ){
                if(  !visited[j] ){
                    string s2 = strs[j] ;
                    sort(s2.begin() , s2.end() );

                    if( s1 == s2 ){
                        group.push_back( strs[j] );
                        visited[j] = true ;
                    }
                }
            }
            ans.push_back( group ) ;
        }     
        return ans ;
    }
};