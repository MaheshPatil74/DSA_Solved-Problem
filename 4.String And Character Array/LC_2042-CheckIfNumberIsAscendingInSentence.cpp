class Solution {
private : 
    bool isNumber( char temp ){
        return (temp >= '0' && temp <= '9') ;
    }
public:
    bool areNumbersAscending(string s) {
        int i = 0 ;
        int maxi = INT_MIN ;
        while( i<s.length() ){

            while( i < s.length() && !isNumber( s[i] ) )
                i++ ; 
            if( i>= s.length() )
                break ;
                
            int num = 0 ;
            while( i < s.length() && isNumber(s[i]) ) {
                int digit = s[i] - '0';

                // optional overflow check
                if(num > INT_MAX/10)
                    return false;

                num = num * 10 + digit;
                i++;                    
            }

            if( num <= maxi )
                return false ;
            else
                maxi = num ;
        }  
        return true ; ;              
    }
};