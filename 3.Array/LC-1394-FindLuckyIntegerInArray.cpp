// Approach 2 : Using Sorting
//  TC : O(N*LogN) , SC : O(1)
class Solution {
public:
    int findLucky(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        int streak = 0;

        for (int i = arr.size() - 1; i >= 0; i--) {
            streak++;
            if (i == 0 || arr[i] != arr[i - 1]) {
                if (arr[i] == streak) 
                    return arr[i];
                streak = 0;
            }
        }
        return -1;
    }
};


// Approach 1 : Brute Force
//  TC : O(N*N) , SC : O(1)
class Solution {
public:
    int findLucky(vector<int>& arr) {
        int res = -1;

        for (int num : arr) {
            int cnt = 0;
            for (int a : arr) 
                if (num == a) 
                    cnt++;
                    
            if (cnt == num) 
                res = max(res, num);
        }

        return res;
    }
};