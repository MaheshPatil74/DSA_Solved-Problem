// Approach 2 : optimal and correct
// TC : O(N) , SC : O(1)
class Solution {
public:
    int numSteps(string s) {
        int steps = 0 ;
        int carry = 0 ;
        // Right se left traverse, last bit skip karo
        for( int i = s.length()-1 ; i>0 ; i-- ){
            if( ( s[i]-'0' + carry ) == 1 ){
                // odd case
                steps += 2 ;
                carry = 1 ;
            }
            else{
                // even case
                steps += 1 ;
            }
        }

        // agar carry bacha hai to ek extra step
        return steps + carry ;
    }
};




// Approach 1 : Wrong for Large input length as Integer Overflow
// TC : O(N) , SC : O(1)
class Solution {
public:
    int numSteps(string s) {
        int n = s.length() ;
        int num = 0 ;

        for( int i = 0 ; i<n ; i++ ){
            num *= 2 ;
            if( s[i] == '1' )
                num += 1 ;                
        }

        int count = 0 ;
        while( num != 0 ){
            if( num%2 == 0 )
                num /= 2 ;
            else
                num += 1 ;
            count++ ;
        }
        return count ;
    }
};