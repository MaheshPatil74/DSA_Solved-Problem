// Approach 2 : Final thinking
// GCD of (N*N) and (N*(N+1)  ) == n 
// TC : O(1) , SC : O(1)
class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        return n ;
    }
};


// Approach 1 : brute force
// TC : O(LogN) , SC : O(1)
class Solution {
public:
    int gcdOfOddEvenSums(int n) {
        long long sumEven = n*(n+1) ;
        long long sumOdd = n*n ;

        while( sumOdd != 0 ){
            int temp = sumOdd ;
            sumOdd = sumEven % sumOdd ;
            sumEven = temp ;
        }
        return sumEven ;
    }
};