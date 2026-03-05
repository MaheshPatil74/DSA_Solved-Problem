// TC : O(N) , SC : O(1)
class Solution {
public:
    int minOperations(string s) {
        int check1 = 0 ;    //count mismatch with pattern "010101"
        int check2 = 0 ;    //count mismatch with pattern "101010"

        for( int i = 0 ; i<s.length() ; i++ ){
            if( (i%2) == 0 ){   //even index check
                if( s[i] != '0' )   check1++;
                if( s[i] != '1' )   check2++;
            }
            else{               //odd index check
                if( s[i] != '1' )   check1++;
                if( s[i] != '0' )   check2++;
            }
        }
        return min(check1,check2) ;
    }
};