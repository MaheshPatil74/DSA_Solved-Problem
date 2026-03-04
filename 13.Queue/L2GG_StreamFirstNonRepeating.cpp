// TC : O(N) , TC : O(1)
class Solution {
  public:
    string firstNonRepeating(string &s) {
        vector<int> freq(26,0) ;
        queue<char> q ;
        string ans = "" ;
        
        for( char ch : s ){
            freq[ ch-'a' ]++ ;
            q.push( ch );
            while( !q.empty() ){
                if( freq[ q.front()-'a' ] > 1 )
                    q.pop() ;
                else{
                    ans.push_back( q.front() ) ;
                    break ;
                }
            }
            
            if( q.empty() )
                ans.push_back('#') ;
        }
        
        return ans ;
            
        
    }
};