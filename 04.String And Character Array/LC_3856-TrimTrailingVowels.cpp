// Approach 1 :
// TC : O(N) , SC : O(1) 
class Solution {
public:
    string trimTrailingVowels(string s) {
        
        int i = s.length()-1 ;
        while( i>=0 ){
            if( s[i]=='a' || s[i]=='e' || s[i]=='i' || s[i]=='o' || s[i]=='u' )
                i--;
            else
                break ;
        }
        return s.substr(0,i+1);
    }
};