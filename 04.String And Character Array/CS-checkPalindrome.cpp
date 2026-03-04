#include <bits/stdc++.h> 
bool checkPalindrome(string s) {
    vector<char> ans;
    for (int i = 0; s[i] != '\0'; i++) {
        // Fixing the check for uppercase letters
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')) {
            // Convert to lowercase for case-insensitive comparison
            if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] = s[i] + 32; // convert uppercase to lowercase
            }
            ans.push_back(s[i]);
        }
    }

    int start = 0 ;
    int end = ans.size() - 1 ;

    while(start<end){
        if( ans[start] != ans[end] ){
            return 0 ;
        }
        else{
            start++ ;
            end-- ;
        }
    }
    return 1 ;
}


/*
void reverseString(vector<char>& s) {
    int start = 0;
    int end = s.size() - 1;

    while (start < end) {
        swap(s[start++], s[end--]);
    }
}

bool checkPalindrome(string s) {
    vector<char> ans;
    for (int i = 0; s[i] != '\0'; i++) {
        // Fixing the check for uppercase letters
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9')) {
            // Convert to lowercase for case-insensitive comparison
            if (s[i] >= 'A' && s[i] <= 'Z') {
                s[i] = s[i] + 32; // convert uppercase to lowercase
            }
            ans.push_back(s[i]);
        }
    }

    vector<char> check = ans;  // Create a copy of 'ans'
    
    // Reverse the vector 'ans' and compare with 'check'
    reverseString(ans);
    
    return check == ans;  // Check if the original vector is the same as reversed
}
*/