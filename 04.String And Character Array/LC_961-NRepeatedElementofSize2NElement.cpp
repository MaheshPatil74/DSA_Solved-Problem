// Approach 3 : Optimal Trick
// Repeated element 1, 2, ya 3 distance ke andar mil jayega
// TC : O(N) , SC : O(1)
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) {
            if(i + 1 < n && nums[i] == nums[i + 1])     return nums[i];
            if(i + 2 < n && nums[i] == nums[i + 2])     return nums[i];
            if(i + 3 < n && nums[i] == nums[i + 3])     return nums[i];
        }
        return -1;
    }
};


// Approach 2 : Using hashSet
// TC : O(N) , SC : O(N)
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        unordered_set<int> st;
        for(int num : nums) {
            if(st.count(num))
                return num;
            st.insert(num);
        }
        return -1;
    }
};

// Approach 1 : Brute force
// TC : O(N*N) , SC : O(1)
class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n = nums.size();
        for(int i = 0; i < n; i++) 
            for(int j = i+1; j < n; j++) 
                if(nums[i] == nums[j])
                    return nums[i] ;
        
        return -1;
    }
};