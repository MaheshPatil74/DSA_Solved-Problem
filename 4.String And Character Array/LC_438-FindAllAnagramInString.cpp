// TC : O(N)
class Solution {
private:
    bool isAllZero(vector<int>& counter ){
        for( int temp : counter )
            if( temp != 0 )
                return false ;
        return true ;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> counter(26,0) ;
        for( char temp : p )
            counter[ temp - 'a']++ ;

        vector<int> ans ;
        int i = 0 , j = 0 ;
        while( j<s.size() ){
            counter[ s[j] - 'a' ]-- ;
            if( j-i+1 == p.size() ){
                if( isAllZero(counter) ){
                    ans.push_back(i) ;
                }
                counter[s[i]-'a']++;
                i++;
            }
            j++ ;
        } 
        return ans ;
        
    }
};