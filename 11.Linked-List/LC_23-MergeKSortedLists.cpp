// Approach 2 : using priority queue
// TC : O(N*LogK) , SC : O(K)           // k << N
class Solution {
public:
    // Custom comparator for min heap
    struct compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; // min heap
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        // Min heap
        priority_queue<ListNode*, vector<ListNode*>, compare> pq;

        // Step 1: push all heads
        for(auto node : lists){
            if(node != NULL)
                pq.push(node);
        }

        // Dummy node
        ListNode* dummy = new ListNode(0);
        ListNode* tail = dummy;

        // Step 2: process heap
        while(!pq.empty()){
            ListNode* smallest = pq.top();
            pq.pop();

            // attach to result
            tail->next = smallest;
            tail = tail->next;

            // push next node of that list
            if(smallest->next != NULL){
                pq.push(smallest->next);
            }
        }

        return dummy->next;
    }
};


// Approach 1 : Brute force => use vector store values and make new list
// TC : O(N*LogN) , SC : O(N)           // total Node = N
class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if( lists.size() == 0 )
            return NULL ;

        // step 1 : store values
        vector<int> values ;
        for( int i = 0 ; i<lists.size() ; i++ ){
            ListNode* temp = lists[i] ;
            while( temp ){
                values.push_back( temp->val ) ;
                temp = temp->next ;
            }
        }
        if( values.empty() )
            return NULL ;

        // step 2 : sort vector
        sort( values.begin() , values.end() );

        // step 3 : create new list from vector
        ListNode* head = new ListNode( values[0] ) ; 
        ListNode* temp = head ;
        for( int i = 1 ; i<values.size() ; i++ ){
            temp->next = new ListNode(values[i]) ;
            temp = temp->next ;
        }
        return head ;
    }
};