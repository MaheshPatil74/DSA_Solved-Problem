// Approach :
// TC : O(N) , SC : O(100) == O(1)
class Solution {
public:
    int sumOfUnique(vector<int>& nums) {
        vector<int> freq(101,0) ;

        for( int num : nums )
            freq[num]++ ;

        long long sum = 0 ;
        for( int i = 1 ; i<=100 ; i++ )
            if( freq[i] == 1 )
                sum += i ;
        return sum ;
    }
};