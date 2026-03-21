// Approach 2 :  efficient as space inplace modify 
// TC : O( N ) , SC : O( 1 )
class Solution {
public:
    string addStrings(string num1, string num2) {
        if( num2.size() > num1.size() )
            swap( num1 , num2 ) ;

        int i = num1.size() - 1 ;
        int j = num2.size() - 1 ;
        int carry = 0 ;

        while( i>=0 ){
            int sum = (num1[i]-'0') + carry ;
            if( j>=0 )
                sum += ( num2[j--] - '0' ) ;

            num1[i--] = ( sum%10 ) + '0' ;
            carry = sum / 10 ;
        }
        
        if( carry )
            num1 = '1' + num1 ;

        return num1 ;
    }
};


// Approach 1 :  using extra space to store ans 
// TC : O( max(N,M) ) , SC : O( max(N,M) )
class Solution {
public:
    string addStrings(string num1, string num2) {
        int i = num1.size() - 1 ;
        int j = num2.size() - 1 ;
        int carry = 0 ;
        string ans = "" ;

        while( i>=0 || j>=0 || carry ){
            int sum = carry ;
            if( i>=0 )
                sum += ( num1[i--] - '0' ) ;
            if( j>=0 )
                sum += ( num2[j--] - '0' ) ;

            ans.push_back(( sum%10 ) + '0' );
            carry = sum / 10 ;
        }
        
        // reverse the array
        int n = ans.size() ;
        for( int i = 0 ; i<n/2 ; i++ )
            swap( ans[i] , ans[n-i-1] ) ;

        return ans ;
    }
};