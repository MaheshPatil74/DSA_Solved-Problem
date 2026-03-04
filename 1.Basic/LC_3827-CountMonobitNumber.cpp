// Approach 2 : (OWN) More Optimal
// TC = O( LogN ) 
// SC = O(1)
class Solution {
public:
    int countMonobit(int n) {
        int count = 0 ;
        int power = 4 ;
        if( n >= 0 )
            count++ ;
        if( n >= 1 )
            count++ ;

        while( (power-1) <= n){
            count++ ;
            power = 2*power ;
        }

        return count ;
    }
};

// Approach 1 : ( OWN )
// TC = O(N) 
// SC = O(1)
class Solution {
public:
    int countMonobit(int n) {
        int count = 0 ;
        int power = 4 ;
        if( n >= 0 )
            count++ ;
        if( n >= 1 )
            count++ ;

        for( int i = 3 ; i<=n ; i = i+2 ){
            if( i == power - 1 ){
                count++ ;
                power = 2 * power ;
            }
        }
        return count ;
    }
};
