// Approach 2 : cyclic sort pattern
// TC : O(N) , SC : O(1)
class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        
        for( int i = 0 ; i<s.size() ; i++ )
            while( indices[i] != i ){
                swap( s[i] , s[indices[i]] ) ;
                swap( indices[i] , indices[indices[i]] ) ;
            }
        return s ;
    }
};


// Approach 1 :
// TC : O(N) , SC : O(N)
class Solution {
public:
    string restoreString(string s, vector<int>& indices) {
        string ans = s ;

        for( int i = 0 ; i<s.length() ; i++ ){
            char element = s[i] ;
            int index = indices[i] ;
            ans[index] = element ; 
        }
        return ans ;
    }
};