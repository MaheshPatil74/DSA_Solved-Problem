// TC : O(M+N) , SC : O(1)
class Solution {
public:
    int getCommon(vector<int>& num1, vector<int>& num2) {
        int idx1 = 0 , idx2 = 0 ;
        while( idx1 < num1.size() && idx2 < num2.size() ){
            if( num1[idx1] == num2[idx2] )
                return num1[idx1] ;
            else if( num1[idx1] < num2[idx2] )
                idx1++ ;
            else
                idx2++ ;
        }
        return -1 ;
    }
};