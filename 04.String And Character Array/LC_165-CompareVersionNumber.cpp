// TC : O(M+N)  ,   SC : O(1)
class Solution {
public:
    int compareVersion(string version1, string version2) {
        int len1 = version1.size() ;
        int len2 = version2.size() ;

        int idx1 = 0 ;
        int idx2 = 0 ;
        while( idx1 < len1 || idx2 < len2 ){
            int num1 = 0 ;
            int num2 = 0 ;

            while( idx1<len1 && version1[idx1]!='.' )
                num1 = num1*10 + ( version1[idx1++] - '0' ) ;

            while( idx2<len2 && version2[idx2]!='.' )
                num2 = num2*10 + ( version2[idx2++] - '0' ) ;

            if( num1<num2 ) return -1 ;
            if( num1>num2 ) return 1 ;

            idx1++ ;    //skip dot
            idx2++ ;    //skip dot
        } 
        return 0 ;
    }
};