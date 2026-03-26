// Approach 3 : Sliding Window + map
// TC : O(N) , SC : O(N)
// Logic : Instead of removing one-by-one, jump pointer directly using last index.
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        
        int left = 0;
        int maxLen = 0;

        for(int right = 0; right < s.size(); right++) {
            
            // If character already seen, move left pointer
            if(mp.count(s[right])) {
                left = max(left, mp[s[right]] + 1);
            }

            // Update last index of character
            mp[s[right]] = right;

            // Update maximum length
            maxLen = max(maxLen, right - left + 1);
        }

        return maxLen;
    }
};


// Approach 2 : Sliding Window + set
// TC : O(2*N) == O(N) , SC : O(N)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> set ;
        int i = 0 ;
        int j = 0 ;
        int maxLen = 0 ;
        while( j<s.size() ){
            if( set.count(s[j]) == 0 ){
                set.insert( s[j] );
                maxLen = max( maxLen , j-i+1 );
                j++ ;
            }
            else{
                set.erase( s[i] );
                i++ ;
            }
        }
        return maxLen ;
    }
};


// Approach 1 : Brute force ==>> generate all substring and then check
// TC : O(N*N) , SC : O(N)
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.length() ;
        int maxLen = 0 ;
        for( int i = 0 ; i<n ; i++ ){
            unordered_set<char> set ;
            for( int j = i ; j<n ; j++ ){
                if( set.count( s[j] ) )
                    break ;
                set.insert( s[j] ) ;
                maxLen = max( maxLen , j-i+1 );
            } 
        }
        return maxLen ;
    }
};