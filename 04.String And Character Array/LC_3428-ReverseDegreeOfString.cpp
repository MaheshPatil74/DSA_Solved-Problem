// TC : O(N) , SC : O(1)
class Solution {
public:
    int reverseDegree(string s) {
        long long prodSum = 0 ;
        for( int i = 0 ; i<s.length() ; i++ )
            prodSum += ( (i+1) * (26-s[i]+'a') )  ;
        return prodSum ;
    }
};