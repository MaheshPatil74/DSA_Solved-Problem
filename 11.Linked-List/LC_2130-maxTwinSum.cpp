// Approach 2 : Optimal
// TC : O(N) , SC : O(1)
class Solution {
public:
    int pairSum(ListNode* head) {
        // Step 1: find middle
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast && fast->next) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // Step 2: reverse second half
        ListNode* prev = NULL;
        while (slow) {
            ListNode* next = slow->next;
            slow->next = prev;
            prev = slow;
            slow = next;
        }

        // Step 3: find max twin sum
        int ans = INT_MIN;
        ListNode* first = head;
        ListNode* second = prev;
        while (second) {
            ans = max(ans, first->val + second->val);
            first = first->next;
            second = second->next;
        }
        return ans;
    }
};


// Approach 1 : Using extra array
// TC : O(N) , SC : O(N)
class Solution {
public:
    int pairSum(ListNode* head) {
        vector<int> nums ;
        ListNode* curr = head ;
        while( curr ){
            nums.push_back( curr->val ) ;
            curr = curr->next ;
        }

        int left = 0 , right = nums.size()-1 ;
        int ans = INT_MIN ; 
        while( left < right ){
            ans = max( ans , nums[left] + nums[right] ) ;
            left++ ;
            right-- ;
        }
        return ans ;
    }
};