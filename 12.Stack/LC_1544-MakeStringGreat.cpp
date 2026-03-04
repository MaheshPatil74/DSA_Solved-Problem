// Approach 2 : Modify Original String act as Stack Pointer 
// TC : O(N) , SC : O(1)
class Solution {
public:
    string makeGood(string s) {
        int top = 0 ;
        for(int i = 0 ; i<s.size() ; i++ ){
            if( top>0 && abs( s[top-1] - s[i] ) == 32 )
                top-- ;     //remove previous character
            else
                s[top++] = s[i] ;
        }
        return s.substr(0,top) ;
    }
};

// Approach 1 : Using string and behaave it as stack 
// TC : O(N) , SC : O(N)
class Solution {
public:
    string makeGood(string s) {
        string ans ;
        for(char ch : s ){
            if( !ans.empty() && abs( ans.back() - ch ) == 32 )
                ans.pop_back() ;
            else
                ans.push_back(ch) ;
        }
        return ans ;
    }
};