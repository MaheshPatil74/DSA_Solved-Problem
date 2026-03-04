// Approach-2 : Optimal ==>> Suffix Max
// T.C. = O(N) , S.C. = O(N)
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size() ;
        vector<int> ans(n) ;
        int rightMax = -1 ;
        for( int i = n-1 ; i>=0 ; --i ){
            ans[i] = rightMax ;
            rightMax = max( rightMax , arr[i] ) ; 
        }
        return ans ;
    }
};

// Approach-1 : Brute Force
// T.C. = O(N^2) , S.C. = O(N)
class Solution {
public:
    vector<int> replaceElements(vector<int>& arr) {
        int n = arr.size() ;
        vector<int> ans(n) ;

        for( int i = 0 ; i<n ; i++ ){
            int maxi = -1 ;
            for( int j = i+1 ; j<n ; j++ ){
                maxi = max( arr[j] , maxi );
            }
            ans[i] = maxi ;
        }
        return ans ;
    }
};