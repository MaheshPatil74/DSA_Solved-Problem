// Approach 2 : Optimal Using Map==>> Instantly check reverse 
// TC : O(N) , SC : O(N)
class Solution {
public:
    int reverseNum(int num) {
        int rev = 0;
        while (num > 0) {
            rev = rev * 10 + (num % 10);
            num /= 10;
        }
        return rev;
    }

    int minMirrorPairDistance(vector<int>& nums) {
        // mapping reverse of Number with index
        unordered_map<int, int> mp; 
        int mini = INT_MAX;

        for (int i = 0; i < nums.size(); i++) {
            // if current number matches some previous reverse
            if (mp.count(nums[i])) 
                mini = min(mini, i - mp[nums[i]]);

            int rev = reverseNum(nums[i]);

            // storing reverse of current number
            mp[rev] = i;
        }

        return mini == INT_MAX ? -1 : mini;
    }
};


// Approach 1 : Brute force 
// TC : O(N*N) , SC : O(1)
class Solution {
public:
    int minMirrorPairDistance(vector<int>& nums) {
        int n = nums.size() ;
        int mini = INT_MAX ;

        for( int i = 0 ; i<n ; i++ ){
            int num = nums[i] ;
            int rev = 0 ;
            while( num > 0 ){
                int d = num%10 ;
                rev = rev*10 + d ;
                num /= 10 ;
            }

            for( int j = i+1 ; j<n ; j++ )
                if( nums[j] == rev )
                    mini = min( mini , abs( i-j ) ) ;
        }
        return mini==INT_MAX ? -1 : mini ; 
    }
};