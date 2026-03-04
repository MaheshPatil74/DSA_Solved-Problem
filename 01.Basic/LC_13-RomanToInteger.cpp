// Approach 2 : Use switch : Reducing map overhead  
// TC : O(N) , SC : O(1) 
class Solution {
private :
    int getVal(char ch){
        switch(ch){
            case 'I': return 1;
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
        }
        return 0;
    }
public:
    int romanToInt(string s) {
        int n = s.length() ;
        int ans = getVal(s[n-1]) ;
        for( int i = n-2 ; i>=0 ; i-- ){
            int curr = getVal(s[i]) ;
            int next = getVal(s[i+1]) ;
            if( curr >= next )
                ans += curr ;
            else
                ans -= curr ;
        }
        return ans ;
    }
};


// Approach 1 : using Map 
// TC : O(N) , SC : O(1) // constant size map
class Solution {
public:
    int romanToInt(string s) {
        static unordered_map<char, int> roman = {
            {'I', 1},
            {'V', 5},
            {'X', 10},
            {'L', 50},
            {'C', 100},
            {'D', 500},
            {'M', 1000}
        };

        int n = s.length() ;
        int ans = roman[ s[n-1] ] ;
        for( int i = n-2 ; i>=0 ; i-- ){
            if( roman[s[i]] >= roman[s[i+1]] )
                ans += roman[s[i]];
            else
                ans -= roman[s[i]];
        }
        return ans ;
    }
};