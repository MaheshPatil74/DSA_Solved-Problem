// TC : O() , SC : O()
class Solution {
public:
    int findLength(ListNode* temp ){
        int len = 0 ;
        while( temp ){
            len++ ;
            temp = temp->next ;
        }
        return len ;
    }

    TreeNode* solve(ListNode* head , int s , int e ){
        if( s>e )
            return NULL ;

        int mid = (s+e)/2 ;
        ListNode* temp = head ;

        int counter = mid ;
        while( counter-- )
            temp = temp->next ;

        TreeNode* node = new TreeNode( temp->val ) ;
        node->left = solve( head , s , mid-1 ) ;
        node->right = solve( head , mid+1 , e ) ;
        return node ;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        int n = findLength(head) ;
        return solve( head , 0 , n-1 ) ;
    }
};