// Approach 2 : without Using extra vector
class Solution {
public:
    void solve( TreeNode* root , long sum , long long &totalSum ){
        if( root == NULL )
            return ;

        if( root->left==NULL && root->right == NULL ){
            sum = sum*10 + root->val ;
            totalSum += sum ;
            return ;
        }

        sum = sum*10 + root->val ;
        solve( root->left , sum , totalSum );
        solve( root->right , sum , totalSum );
    }

    int sumNumbers(TreeNode* root) {
        long long totalSum = 0 ;
        solve( root , 0 , totalSum );
        return totalSum ;
    }
};



// Approach 1 : Using extra vector
class Solution {
public:
    void solve( TreeNode* root , long sum , vector<long> &sums ){
        if( root == NULL )
            return ;

        if( root->left==NULL && root->right == NULL ){
            sum = sum*10 + root->val ;
            sums.push_back( sum );
            return ;
        }

        sum = sum*10 + root->val ;
        solve( root->left , sum , sums );
        solve( root->right , sum , sums );
    }

    int sumNumbers(TreeNode* root) {
        vector<long> sums ;
        long sum = 0 ;
        solve( root , sum , sums );

        long long total = 0 ;
        for( long i : sums )
            total += i ;
        return total ;
    }
};