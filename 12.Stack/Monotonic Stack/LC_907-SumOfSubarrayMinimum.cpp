// Approach 1 : TLE occur
// TC : O(N*N) , SC : O(1)
class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        int result  = 0 ;
        for( int i = 0 ; i<arr.size() ; i++ ){
            int mini = INT_MAX ;
            for( int j = i ; j<arr.size() ; j++ ){
                mini = min( mini , arr[j] ) ;
                result = (result + mini)%1000000007 ;
            }
        }
        return result ;
    }
};