// Approach 2 : Monotonic Stack
// TC : O(N) , SC : O(N)
class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        stack<TreeNode*> st;

        for(int num : nums) {
            TreeNode* curr = new TreeNode(num);

            while(!st.empty() && st.top()->val < num) {
                curr->left = st.top();
                st.pop();
            }

            if(!st.empty()) 
                st.top()->right = curr;

            st.push(curr);
        }

        while(st.size() > 1) 
            st.pop();

        return st.top();
    }
};



// Approach 1 : Recursive with find maxi
// TC : O(N*LogN) , SC : O(N)
class Solution {
public:
    TreeNode* solve(vector<int>& nums , int start , int end ){
        if( start > end )
            return NULL ;

        int maxi = nums[start] ;
        int maxIndex = start ;
        for( int i = start ; i<=end ; i++ )
            if( nums[i] > maxi ){
                maxi = nums[i] ;
                maxIndex = i ;
            }

        TreeNode* node = new TreeNode(maxi) ;
        node->left = solve(nums , start , maxIndex-1 );
        node->right = solve(nums , maxIndex+1 , end );
        return node ;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return solve(nums , 0 , nums.size()-1 ) ;
    }
};