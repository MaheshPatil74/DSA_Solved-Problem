// Approach-1 : boolean array to track presence of each character
// Time Complexity: O(N) , Space Complexity: O(1)
class Solution {
public:
    bool checkIfPangram(string sentence) {
        
        if( sentence.length() < 26 )
            return false ;

        vector<bool> ans(26,false) ;
        for( char temp : sentence ){
            int index = temp - 'a' ;
            if( !ans[index] )
                ans[index] = true ;
        }

        for( int i = 0 ; i<26 ; i++ ){
            if( ans[i] == false )
                return false ;
        }
        return true ;
    }
};