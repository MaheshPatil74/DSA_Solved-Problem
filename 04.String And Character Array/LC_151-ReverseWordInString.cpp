// TC : O(N) , SC : O(1)
class Solution {
private:
    void reverseString(string& temp, int left, int right){
        while(left < right)
            swap(temp[left++], temp[right--]);
    }

public:
    string reverseWords(string s) {
        int n = s.length();

        // Step 1: Remove extra spaces
        int idx = 0;
        int j = 0;
        while(j < n){
            while(j < n && s[j] == ' ') j++;               // skip spaces
            while(j < n && s[j] != ' ') s[idx++] = s[j++]; // copy word
            while(j < n && s[j] == ' ') j++;               // skip spaces
            if(j < n) s[idx++] = ' ';                      // add single space
        }
        s.resize(idx);

        // Step 2: Reverse whole string
        reverseString(s, 0, s.size() - 1);

        // Step 3: Reverse each word
        int start = 0;
        for(int end = 0; end <= s.size(); end++){
            if(end == s.size() || s[end] == ' '){
                reverseString(s, start, end - 1);
                start = end + 1;
            }
        }
        return s;
    }
};