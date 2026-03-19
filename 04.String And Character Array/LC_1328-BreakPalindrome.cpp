// TC : O(N) , SC : O(1)
class Solution {
public:
    string breakPalindrome(string palindrome) {
        int n = palindrome.size();

        // Case 1: single character
        if(n == 1) return "";

        // Case 2: try to replace in first half
        for(int i = 0; i < n / 2; i++){
            if(palindrome[i] != 'a'){
                palindrome[i] = 'a';
                return palindrome;
            }
        }

        // Case 3: all 'a'
        palindrome[n - 1] = 'b';
        return palindrome;
    }
};