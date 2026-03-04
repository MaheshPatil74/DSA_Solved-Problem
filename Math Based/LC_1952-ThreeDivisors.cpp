// Approach 2 : Better than 1 
// TC : O(N)  , SC : O(1)
// Key Fact: A number has exactly 3 divisors, iff it is the square of a prime number
class Solution {
private :
    bool isPrime( int root ){
        if( root < 2 )
            return false ;
        for( int i = 2 ; i*i<=root ; i++ )
            if( root%i == 0 )
                return false ;
        return true ;
    }
public:
    bool isThree(int n) {
        int root = sqrt(n) ;

        // Check if n is perfect square
        if( root * root != n )
            return false ;

        // Check if root is prime
        return isPrime(root) ;
    }
};


// Approach 1 : Slightly slower
// TC : O(N)  , SC : O(1)
class Solution {
public:
    bool isThree(int n) {
        if( n <= 3 )
            return  false ;

        int count = 2 ;
        for( int i = 2 ; i<=n/2 ; i++ )
            if( n%i == 0 ){
                count++ ;
                if( count>3 )
                    return false ;
            }
        return ( count == 3 ) ;
    }
};