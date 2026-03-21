// Approach 2 — Optimal (Floyd Cycle Detection)
// Slow moves 1 step, fast moves 2 steps.
// If they meet => cycle
// If fast becomes 1 => happy
// TC : O(LogN) , SC : O(1)
class Solution {
public:
    int squareSum( int n ){
        int sum = 0 ;
        while( n ){
            int digit = n%10 ;
            n /= 10 ;
            sum += ( digit*digit ) ;
        }
        return sum ;
    }

    bool isHappy(int n) {
        int slow = n ;
        int fast = squareSum(n) ;

        while( fast != 1 && slow!=fast ){
            slow = squareSum(slow) ;
            fast = squareSum( squareSum( fast ));
        }
        return fast==1 ;
    }
};


// Approach 1 — Using Set (Cycle Detection)
// If a number repeats → cycle → not happy
// TC : O(LogN) , SC : O(LogN)
class Solution {
public:
    int squareSum( int n ){
        int sum = 0 ;
        while( n ){
            int digit = n%10 ;
            n /= 10 ;
            sum += ( digit*digit ) ;
        }
        return sum ;
    }
    bool isHappy(int n) {
        unordered_set<int> st ;
        while( n != 1 && !st.count(n) ){
            st.insert( n ) ;
            n = squareSum(n) ;
        }
        return n==1 ;
    }
};