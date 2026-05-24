// TC : O(N) , SC : O(128) == O(1)
class Solution {
public:
    int passwordStrength(string password) {
        vector<bool> visited(128,false) ;
        int strength = 0 ;

        for( char c : password ){
            if( visited[c] )
                continue ;

            if( c>='a' && c<='z' )
                strength += 1 ; 
            else if( c>='A' && c<='Z' )
                strength += 2 ;
            else if( c>='0' && c<='9' )
                strength += 3 ;
            else
                strength += 5 ;

            visited[c] = true ;
        }
        return strength ;
    }
};