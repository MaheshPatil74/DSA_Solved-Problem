// Both code are same only writing diffrence
// TC : O(N) , SC : O(1)
class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        int i = 0;
        for(string &word : words) {
            for(char c : word) {
                if(i >= s.length() || s[i] != c)
                    return false;
                i++;
            }
            if(i == s.length())
                return true;
        }
        return i == s.length();
    }
};


// TC : O(N) , SC : O(1)
class Solution {
public:
    bool isPrefixString(string s, vector<string>& words) {
        
        int i = 0 ;
        int j = 0 ;
        int index = 0 ;

        while( i<s.length() && index<words.size() ){
            string word = words[index] ;

            while( j<word.length() ){
                if( s[i] != word[j] )
                    return false ;
                j++ ;
                i++ ;
            }
            index++ ;
            j = 0 ;
        }
        
        return i==s.length() ;
    }
};