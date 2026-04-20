// Approach 2 : Optimised By Space
// TC : O(N) , SC : O(1)
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size() ;
        long long totalSum = 0 ;
        for( int num :  nums )
            totalSum += num ;

        long long leftSum = 0 ;
        int count = 0 ;
        for( int i = 0 ; i<n-1 ; i++ ){
            leftSum += nums[i] ;
            if( leftSum >= ( totalSum - leftSum ) )
                count++ ;
        }
        return count ;
    }
};


// Approach 1 :
// TC : O(N) , SC : O(N)
class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n = nums.size() ;
        vector<long long> suffixSum(n) ;

        suffixSum[n-1] = 0 ;
        for( int i = n-2 ; i>=0 ; i-- )
            suffixSum[i] = nums[i+1] + suffixSum[i+1] ;

        long long sum = 0 ;
        int count = 0 ;
        for( int i = 0 ; i<n-1 ; i++ ){
            sum += nums[i] ;
            if( sum >= suffixSum[i] )   
                count++ ;
        }
        return count ;
    }
};