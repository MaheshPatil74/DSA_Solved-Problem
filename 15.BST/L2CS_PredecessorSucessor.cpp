// TC = O(n) and SC = O(1)
pair<int, int> predecessorSuccessor(TreeNode *root, int key)
{
    // Write your code here.
    TreeNode * temp = root ;
    int pred = -1 ;
    int succ = -1 ;

    while( temp != NULL && temp->data != key ){
        if(temp->data > key ){
            succ = temp->data;
            temp = temp->left ;
        }
        else{
            pred = temp->data;
            temp = temp->right ;
        }
    }

    if(temp == NULL){
        // Key not found, return current pred and succ
        return make_pair(pred, succ);
    }
    

    // Pred and Succ
    // pred
    TreeNode * leftTree = temp->left ;
    while(leftTree != NULL ){
        pred = leftTree->data;
        leftTree = leftTree->right ;
    }

    // succ
    TreeNode * rightTree = temp->right ;
    while(rightTree != NULL ){
        succ = rightTree->data;
        rightTree = rightTree->left ;
    }

    pair<int, int> ans = make_pair(pred,succ) ;
    return ans ;
}