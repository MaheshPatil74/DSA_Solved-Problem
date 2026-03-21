// Approach 3 : Reservoir Sampling
// TC : O(N) , SC : O(1)
class Solution {
public:
    ListNode* head;
    Solution(ListNode* head) {
        this->head = head;
    }

    int getRandom() {
        int result = head->val;
        ListNode* curr = head->next;
        int i = 2;
        while(curr){
            if(rand() % i == 0){
                result = curr->val;
            }
            curr = curr->next;
            i++;
        }
        return result;
    }
};

// Approach 2 : without extra array
// TC : O(N) per call , SC : O(1)
class Solution {
public:
    ListNode* head ;
    Solution(ListNode* head) {
        this->head = head ;
    }
    
    int getRandom() {
        int len = 0 ;
        ListNode* temp = head ;
        while( temp ){
            len++ ;
            temp = temp->next ;
        }

        temp = head ;
        int randIdx = rand() % len ;
        while( randIdx-- ){
            temp = temp->next ;
        }
        return temp->val ;
    }
};




// Approach 1 : Using extra array
// TC : O(N) , SC O(N)
class Solution {
public:
    vector<int> arr ;
    Solution(ListNode* head) {
        while( head ){
            arr.push_back(head->val) ;
            head = head->next ;
        }
    }
    
    int getRandom() {
        int idx = rand() % arr.size() ;
        return arr[idx] ;
    }
};