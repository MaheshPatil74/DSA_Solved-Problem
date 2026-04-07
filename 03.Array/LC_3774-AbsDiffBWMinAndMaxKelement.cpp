// Approach 2 : Optimal using frequency vector
// TC : O(N) , SC : O(1)
class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        vector<int> freq(101, 0);
        for (int num : nums)
            freq[num]++;
        vector<int> freq2 = freq; // copy for largest

        int leftSum = 0, rightSum = 0;
        int leftCount = 0, rightCount = 0;

        // k smallest
        for (int i = 1; i <= 100 && leftCount < k; i++) {
            while (freq[i] > 0 && leftCount < k) {
                leftSum += i;
                freq[i]--;
                leftCount++;
            }
        }

        // k largest
        for (int i = 100; i >= 1 && rightCount < k; i--) {
            while (freq2[i] > 0 && rightCount < k) {
                rightSum += i;
                freq2[i]--;
                rightCount++;
            }
        }

        return abs(leftSum - rightSum);
    }
};

// Approach 1 : Sorting 
// TC : O(N*LogN) , SC : O(1)
class Solution {
public:
    int absDifference(vector<int>& nums, int k) {
        
        sort( nums.begin() , nums.end() ) ;
        int n = nums.size() ;
        int leftSum = 0 , rightSum = 0 ;
        for( int i = 0 ; i<k ; i++ ){
            leftSum += nums[i] ;
            rightSum += nums[n-i-1] ;
        }
        return abs( leftSum - rightSum ) ;
    }
};