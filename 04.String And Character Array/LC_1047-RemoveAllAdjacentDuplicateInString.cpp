// Approach 3 : Using two pointers (stack simulation)
// Time Complexity: O(n)
// Space Complexity: O(1) 
class Solution {
public:
    string removeDuplicates(string s) {
        int j = 0;   // stack pointer

        for (int i = 0; i < s.length(); i++) {
            s[j] = s[i];   // push

            if (j > 0 && s[j] == s[j - 1])
                j -= 2;   // pop twice (remove duplicate pair)

            j++;
        }

        return s.substr(0, j);
    }
};


// Approach 2 : (optimal)
// Time Complexity: O(n)
// Space Complexity: O(n)
class Solution {
public:
    string removeDuplicates(string s) {
        string ans = "";
        for( char ch : s ){
            if( !ans.empty() && ans.back() == ch )
                ans.pop_back() ;
            else
                ans.push_back(ch) ;
        }
        return ans ;
    }
};

// Approach 1 : Using erase function of string
// Time Complexity: O(n^2) in worst case, O(n) in average case
// Space Complexity: O(1)
class Solution {
public:
    string removeDuplicates(string s) {
        
        int i = 0 ;
        while( i+1<s.length() && s.length() != 0 ){

            if( s[i] == s[i+1] ){
                s.erase(i , 2 ) ;
                i = i - 1 ;
                if( i<0 )
                    i = 0 ;
            }
            else{
                i++ ;
            }
        }
        return s ;
    }
};