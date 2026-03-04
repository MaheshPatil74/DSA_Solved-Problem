// approach 2 : Find middle then reverse list after middle then compare
// TC : O(N) , SC : O(1)
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if( head == NULL )
            return true ;
        vector<int> arr ;
        ListNode* temp = head ;
        while( temp != NULL ){
            arr.push_back(temp->val) ;
            temp = temp->next ;
        }
        int l = 0  , r = arr.size()-1 ;
        while( l<r ){
            if( arr[l] != arr[r] )
                return false ;
            l++ ;
            r-- ;
        }
        return true ;
    }
};

// approach 1 : using extra array and check array is palindrome
// TC : O(N) , SC : O(N)
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        if( head == NULL )
            return true ;
        vector<int> arr ;
        ListNode* temp = head ;
        while( temp != NULL ){
            arr.push_back(temp->val) ;
            temp = temp->next ;
        }
        int l = 0  , r = arr.size()-1 ;
        while( l<r ){
            if( arr[l] != arr[r] )
                return false ;
            l++ ;
            r-- ;
        }
        return true ;
    }
};