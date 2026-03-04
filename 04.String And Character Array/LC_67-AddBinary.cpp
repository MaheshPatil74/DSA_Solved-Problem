// TC : O( max(N,M) )
// SC : O( max(N,M) )

class Solution {
public:
    string addBinary(string a, string b) {
        if( a == "0" )
            return b ;
        if( b == "0" )
            return a ;

        string res = "" ;

        int i = a.length()-1 ;
        int j = b.length()-1 ;
        int carry = 0 ;

        while( i>=0 || j>=0 || carry > 0 ){
            int digitA = (i>=0) ? a[i]-'0' : 0 ;
            int digitB = (j>=0) ? b[j]-'0' : 0 ;

            int total = digitA + digitB + carry ;
            res += (total%2)+'0' ;
            carry = total/2 ;
            i--;
            j--;
        }
        
        reverse( res.begin() , res.end() );
        return res ;
    }
};