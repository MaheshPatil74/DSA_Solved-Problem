// Approach 2 : Slight Optimisation in approach 1 
// TC : ( (N+M)*d) == (N+M) , SC : O(N*d)
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<int> st ;
        for( int num : arr1 )
            while( num > 0 ){
                st.insert( num ) ;
                num /= 10 ;
            }

        int maxPrefix = 0 ;
        for( int num : arr2 )
            while( num > 0 ){
                if( st.count(num) ){
                    maxPrefix = max( maxPrefix , (int)to_string(num).size() ); 
                    break ;
                }
                num /= 10 ;
            }

        return maxPrefix ;
    }
};


// Approach 1 : better approach 
// TC : ( (N+M)*d) == (N+M) , SC : O(N*d)
class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_set<string> st ;
        for( int num : arr1 ){
            string str = to_string( num ) ;
            string temp = "" ;

            for( int j = 0 ; j<str.length() ; j++ ){
                temp += str[j] ;
                st.insert( temp ) ;
            }
        }

        int maxPrefix = 0 ;
        for( int num : arr2 ){
            string str = to_string(num) ;
            string temp = "" ;

            for( int j = 0 ; j<str.length() ; j++ ){
                temp += str[j] ;
                if( st.count(temp) && temp.length() > maxPrefix )
                    maxPrefix = temp.length() ;
            }
        }

        return maxPrefix ;
    }
};