// Approach 1 : using hashmap ==> counting frequency , then for even freq add all and for odd frequency add all - 1 ;
// tC : O(N) , sc : O(N) 
class Solution {
public:
    int longestPalindrome(string s) {
        unordered_map<char,int> freq ;

        for( char c : s )
            freq[c]++ ;

        int length = 0 ;
        int oddFound = false ;
        for( auto it : freq ){
            if( it.second % 2 == 0 )
                length += it.second ;
            else{
                length += it.second - 1 ;
                oddFound = true ;
            }
        }

        if( oddFound )
            length += 1 ;
        return length ;
    }
};