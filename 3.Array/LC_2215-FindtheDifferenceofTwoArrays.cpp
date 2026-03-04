// Approach 2: Using Hash Sets
// Time Complexity: O(N + M) where N and M are the sizes of nums1 and nums2 respectively.
// Space Complexity: O(N + M)
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {

        unordered_set<int> s1(nums1.begin(), nums1.end());
        unordered_set<int> s2(nums2.begin(), nums2.end());

        vector<vector<int>> ans(2);

        for(int x : s1) {
            if(s2.find(x) == s2.end())
                ans[0].push_back(x);
        }

        for(int x : s2) {
            if(s1.find(x) == s1.end())
                ans[1].push_back(x);
        }

        return ans;
    }
};

// Approach 1: Sorting and Two Pointers
// Time Complexity: O(nlogn + mlogm) where n and m are the sizes of nums1 and nums2 respectively.
// Space Complexity: O(1) ignoring the space required for the output.
class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        vector<vector<int>> ans(2) ;

        sort( nums1.begin() , nums1.end() );
        sort( nums2.begin() , nums2.end() );

        int i = 0 ;
        int j = 0 ;

        while( i<nums1.size() && j<nums2.size() ){
            if( i>0 && nums1[i]==nums1[i-1]){
                i++ ;
                continue ;
            }

            if( j>0 && nums2[j]==nums2[j-1]){
                j++ ;
                continue ;
            }

            if( nums1[i] == nums2[j] ){
                i++ ;
                j++ ;
            }
            else if( nums1[i] < nums2[j] ){
                ans[0].push_back(nums1[i]) ;
                i++ ;
            }
            else{
                ans[1].push_back( nums2[j] );
                j++ ;
            }
        }

        while( i<nums1.size() ){
            if( i>0 && nums1[i]==nums1[i-1]){
                i++ ;
                continue ;
            }
            ans[0].push_back(nums1[i]);
            i++ ;
        }

        while( j<nums2.size() ){
            if( j>0 && nums2[j]==nums2[j-1]){
                j++ ;
                continue ;
            }
            ans[1].push_back(nums2[j]);
            j++ ;
        }

        return ans ;
    }
};