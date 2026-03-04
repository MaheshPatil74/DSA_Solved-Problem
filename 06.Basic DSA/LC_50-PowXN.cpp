class Solution {
public:
    double myPow(double x, int n) {
        if( n==0 ) return 1.0 ;
        if( x==0 ) return 0.0 ;
        if( x==1 ) return 1.0 ;
        if( x == -1 && n%2==0 ) return 1.0 ;
        if( x == -1 && n%2==1 ) return -1.0 ;        
        
        long long binForm = n;

        if (n < 0) {
            x = 1.0 / x;  
            binForm = -binForm;
        }

        double ans = 1.0 ;
        while( binForm > 0 ){
            if( binForm & 1 )
                ans = ans * x ;

            x = x*x ;
            binForm = binForm>>1 ;
        }
        return ans ;
    }
};