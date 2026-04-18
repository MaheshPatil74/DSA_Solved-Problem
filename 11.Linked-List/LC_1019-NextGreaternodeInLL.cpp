// Approach 2 : Optimal 
// TC : O(N) , SC : O(N)
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> vals;
        
        // Step 1: Convert list to array
        while(head){
            vals.push_back(head->val);
            head = head->next;
        }
        
        int n = vals.size();
        vector<int> ans(n, 0);
        stack<int> st;  // stores indices
        
        for(int i = 0; i < n; i++){
            while(!st.empty() && vals[i] > vals[st.top()]){
                ans[st.top()] = vals[i];
                st.pop();
            }
            st.push(i);
        }
        
        return ans;
    }
};




// Approach 1 : Brute Force
// TC : O(N*N) , SC : O(N)
class Solution {
public:
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ans ;
        ListNode* curr = head ;
        while( curr ){
            ans.push_back( curr->val ) ;
            curr = curr->next ;
        }

        for( int i = 0 ; i<ans.size()-1 ; i++ ){
            int j = i+1 ;
            while( j<ans.size() && ans[j] <= ans[i] )
                j++ ;
            ans[i] = ( j==ans.size() ) ? 0 : ans[j] ;
        }
        ans[ans.size()-1] = 0 ;
        return ans ;
    }
};