// Approach 2 : single pass with mind think
// TC : O(N) , SC : O(1)
class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int totalSum = 0;
        for(int num : nums)
            totalSum += num;

        if(totalSum % 2 == 0)
            return nums.size() - 1;

        return 0;
    }
};


// Approach 1 : two pass
// TC : O(N) , SC : O(1)
class Solution {
public:
    int countPartitions(vector<int>& nums) {
        long long totalSum = 0 ;
        for( int num : nums )
            totalSum += num ;

        int leftSum = 0 , rightSum = totalSum ;
        int count = 0 ;
        for( int i = 0 ; i+1<nums.size() ; i++ ){
            leftSum += nums[i] ;
            rightSum -= nums[i] ;
            if( (leftSum - rightSum)%2 == 0 )
                count++ ;
        }
        return count ;
    }
};