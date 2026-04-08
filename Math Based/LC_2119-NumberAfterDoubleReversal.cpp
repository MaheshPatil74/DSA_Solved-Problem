// Approach 2 : Optimal
// TC : O(1) , SC : O(1)
class Solution {
public:
    bool isSameAfterReversals(int num) {
        if( num == 0 )
            return true ;

        return ( num%10 == 0 ) ? false : true ;
    }
};

// Approach 1 : Brute force
// TC : O(d) where d = No. of digit  , SC : O(1)
class Solution {
public:
    bool isSameAfterReversals(int num) {
        int rev1 = 0 ;
        int first = num ;
        while( first > 0 ){
            int digit = first%10 ;
            rev1 = rev1*10 + digit ;
            first /= 10 ;
        }

        int rev2 = 0 ;
        while( rev1 > 0 ){
            int digit = rev1%10 ;
            rev2 = rev2*10 + digit ;
            rev1 /= 10 ;
        }

        return ( rev2 == num ) ;
    }
};