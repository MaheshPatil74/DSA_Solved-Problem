// Approach 2 : doubled string  and find
// TC : O(N) , SC : O(N)
class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length())
            return false;
        return ( s+s ).find(goal) != string::npos ;
    }
};

// Approach 1 : Brute force
// TC : O(N*N) , SC : O(1)
class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.length() != goal.length())
            return false;

        for (int i = 0; i < s.length(); i++) {
            if (s == goal)
                return true;

            char first = s[0];
            s.erase(0, 1);
            s.push_back(first);
        }
        return false;
    }
};