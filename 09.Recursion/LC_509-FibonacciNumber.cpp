
/*
// Without Recursion-->
class Solution {
    public:
        int fib(int n) {
            long long int fib1 = 0;
            long long int fib2 = 1 ;
    
            if(n==0){
                return fib1 ;
            }
    
            if(n==1){
                return fib2 ;
            }
    
            long long int next ;
            int count = 2 ;
            while( count<=n ){
                next = fib1 + fib2 ;
                fib1 = fib2 ;
                fib2 = next ;
                count++ ;
            }
    
            return next ;
            
        }
};
*/    

/*
// Using Recursion
class Solution {
public:
    int fib(int n) {
        
        if( n==0 ){
            return 0 ;
        }

        if( n==1 ){
            return 1 ;
        }
        
        int ans = fib(n-1) + fib(n-2) ;
        return ans ;
    }
};
*/