// 2058. Find the Minimum and Maximum Number of Nodes Between Critical Points

// TC : O(N)
// SC : O(1)
class Solution {
private :
    bool checkCriticalPoint(ListNode*& prev , ListNode*& curr ){
        return ( 
                 ( prev->val < curr->val && curr->val > curr->next->val ) || 
                 ( prev->val > curr->val && curr->val < curr->next->val ) 
               );
    }
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if( head == NULL || head->next == NULL || head->next->next == NULL )
            return {-1,-1} ;

        ListNode* prev = head ;
        ListNode* curr = head->next ;
        int index = 1 ;
        int firstCriticalIndex = -1 ;
        int lastCriticalIndex = -1 ;
        int minDist = INT_MAX ;

        while( curr->next ){
            if( checkCriticalPoint(prev,curr) ){
                if( firstCriticalIndex == -1 )
                    firstCriticalIndex = index ;
                else
                    minDist = min( minDist , index - lastCriticalIndex );  

                lastCriticalIndex = index ;
            }
            prev = curr ;
            curr = curr->next ;
            index++ ;
        }

        if( firstCriticalIndex == lastCriticalIndex)
            return {-1,-1};
        return {minDist , lastCriticalIndex-firstCriticalIndex} ;
    }
};