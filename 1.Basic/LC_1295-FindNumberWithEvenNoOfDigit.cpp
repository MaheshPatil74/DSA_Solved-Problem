// Approach 2 : Counting Number of digit in each number then check for even
// TC : O(N*d)==O(N)  // SC : O(1)
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0 ;
        for( int num : nums ){
            int totalDigit = 0 ;
            while( num != 0 ){
                totalDigit++ ;
                num /= 10 ;
            }
            if( totalDigit % 2 == 0 )
                count++ ;
        }
        return count ;
    }
};

// Approach 1 : Using String Conversion Method
// TC : O(N*d)==O(N)  where, d = No.of digit in each Number which is maximum 6 according to constraint
// SC : O(1) 
class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int count = 0 ;
        for( int num : nums ){
            int temp = to_string(num).length() ;
            if( temp%2 == 0 )
                count++ ;
        }
        return count ;
    }
};