// Approach 2 : using maths Formula of AP
// TC : O(1)
class Solution {
public:
    int totalMoney(int n) {
        int weeks = n/7 ;
        int days = n%7 ; 
        int sumWeeks = (weeks*28) + 7*(weeks * (weeks-1)) / 2 ;
        int sumDays = days * (weeks + 1) + (days * (days-1)) / 2 ;
        return sumWeeks + sumDays ;
    }
};

// Approach 1 : using loop
// TC : O(N)
class Solution {
public:
    int totalMoney(int n) {
        int ans = 0 , start = 1 , current ;   
        for( int day = 1 ; day <= n ; day++ ){
            if( day % 7 == 1 )
                current = start++ ;
            
            ans += current ;
        }
        return ans ;
    }
};