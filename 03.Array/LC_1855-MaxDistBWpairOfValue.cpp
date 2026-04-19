// Approach 2 : Optimal
// TC :O(N+M) , SC : O(1)
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int maxi = 0 ;
        int i = 0 , j = 0 ;
        while( i<nums1.size() && j<nums2.size() ){
            if( nums1[i] <= nums2[j] ){
                maxi = max( maxi , j-i ) ;
                j++ ; 
            }
            else
                i++ ;
        }
        return maxi ;
    }
};

// Approach 1 : TLE Occur
// TC :O(N*M) , SC : O(1)
class Solution {
public:
    int maxDistance(vector<int>& num1, vector<int>& num2) {
        int maxi = 0 ;
        for( int i = 0 ; i<num1.size() ; i++ )
            for( int j = i ; j<num2.size() ; j++ )
                if( num1[i]<=num2[j] )
                    maxi = max( maxi , j-i ) ;
        return maxi ;
    }
};