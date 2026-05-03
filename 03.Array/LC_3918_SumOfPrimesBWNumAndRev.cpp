// Approach 2 : Slight optimal by sieve of erastothesis
class Solution {
public:
    int reverseNum(int n) {
        int rev = 0;
        while(n > 0) {
            rev = rev * 10 + n % 10;
            n /= 10;
        }
        return rev;
    }

    long long sumOfPrimes(int n) {
        int rev = reverseNum(n);

        int L = min(n, rev);
        int R = max(n, rev);

        vector<bool> prime(R + 1, true);

        prime[0] = prime[1] = false;

        for(int i = 2; i * i <= R; i++) 
            if(prime[i]) 
                for(int j = i * i; j <= R; j += i)
                    prime[j] = false;

        long long sum = 0;

        for(int i = L; i <= R; i++) 
            if(prime[i]) sum += i;
        return sum;
    }
};



// Approach 1 :  
class Solution {
public:
    int reverseNum( int num ){
        int rev = 0 ;
        while( num > 0 ){
            rev = rev*10 + num%10 ;
            num /= 10 ;
        }
        return rev ;
    }

    bool isPrime( int n ){
        if( n <= 1 )        return false ;
        if( n == 2 )        return true ;
        if( n%2 == 0 )      return false ;

        for( int i = 3 ; i*i <= n ; i++ )
            if( n%i == 0 )  return false ;
        return true ;
    }
    int sumOfPrimesInRange(int n) {
        int rev = reverseNum(n) ;

        int l = min(n,rev) ;
        int r = max(n,rev) ;
        long long sum = 0 ;
        for( int i = l ; i<=r ; i++ ){
            if( isPrime(i) )
                sum += i ;
        }
        return sum ;
    }
};