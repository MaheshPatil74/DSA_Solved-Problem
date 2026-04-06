// Approach 2 : Optimal Greedy
// Idea : Since zeros must be replaced with at least 1, the minimum possible sum of an array is :    sum + number_of_zeros 
// Because each zero → replaced by at least 1. 
// TC : O(M+N) , SC : O(1)
class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0, sum2 = 0;
        int z1 = 0, z2 = 0;

        for (int x : nums1) {
            sum1 += x;
            if (x == 0) z1++;
        }

        for (int x : nums2) {
            sum2 += x;
            if (x == 0) z2++;
        }

        long long minSum1 = sum1 + z1;
        long long minSum2 = sum2 + z2;

        if (minSum1 < minSum2 && z1 == 0) return -1;
        if (minSum2 < minSum1 && z2 == 0) return -1;

        return max(minSum1, minSum2);
    }
};



// Approach 1 : 
// TC : O(M+N) , SC : O(1)
class Solution {
public:
    long long minSum(vector<int>& nums1, vector<int>& nums2) {
        long long sum1 = 0 , sum2 = 0 ;
        int zeroCount1 = 0 , zeroCount2 = 0 ;
        for( int i = 0 ; i<nums1.size() ; i++ ){
            if( nums1[i] == 0 ){
                zeroCount1++ ;
                nums1[i] = 1 ;
            }
            sum1 += nums1[i] ;
        }

        for( int i = 0 ; i<nums2.size() ; i++ ){
            if( nums2[i] == 0 ){
                zeroCount2++ ;
                nums2[i] = 1 ;
            }
            sum2 += nums2[i] ;
        }

        if( sum1 > sum2 && zeroCount2==0 )
            return -1 ;
        if( sum1 < sum2 && zeroCount1==0 )
            return -1 ;

        return ( sum1>sum2 ) ? sum1 : sum2 ;        
    }
};