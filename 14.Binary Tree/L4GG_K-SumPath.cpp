// TLE problem
class Solution {
  public:
    void solve(Node* root, int k, int &count, vector<int> path) {
        //base case
        if(root == NULL)
            return ;
        
        // Add current node to path
        path.push_back(root->data);
        
        // Recurse left
        solve(root->left, k, count, path);
        // Recurse right
        solve(root->right, k, count, path);
        
        // Check if there is a path ending at this node which sums to k
        //check for K Sum
        int size = path.size();
        int sum = 0;
        for(int i = size-1; i>=0; i--)  {
            sum += path[i];
            if(sum == k)
                count++;
        }
        path.pop_back();
    }
    
    int sumK(Node *root,int k)  {
        vector<int> path;
        int count = 0;
        solve(root, k, count, path);
        return count;
    }
};