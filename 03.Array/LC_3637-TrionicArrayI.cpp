// Approach 2
// TC : O(N) , SC : O(1)
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return false;

        int phase = 1;   // 1: inc, 2: dec, 3: inc

        for(int i=0; i+1<n; i++) {

            if(phase == 1) {
                if(nums[i] < nums[i+1]) continue;
                else if(nums[i] > nums[i+1]) phase = 2;
                else return false;      // equal case
            }

            else if(phase == 2) {
                if(nums[i] > nums[i+1]) continue;
                else if(nums[i] < nums[i+1]) phase = 3;
                else return false;
            }

            else {
                if(nums[i] < nums[i+1]) continue;
                else return false;
            }
        }

        return phase == 3;   // last phase reach hona chahiye
    }
};


// Approach 1 
// TC : O(N) , SC : O(1)
class Solution {
public:
    bool isTrionic(vector<int>& nums) {
        int n = nums.size();
        if(n < 3) return false;

        int i = 0;

        // Phase 1: strictly increasing
        int cnt1 = 0;
        while(i+1 < n && nums[i] < nums[i+1]) {
            i++;
            cnt1++;
        }

        // Phase 2: strictly decreasing
        int cnt2 = 0;
        while(i+1 < n && nums[i] > nums[i+1]) {
            i++;
            cnt2++;
        }

        // Phase 3: strictly increasing
        int cnt3 = 0;
        while(i+1 < n && nums[i] < nums[i+1]) {
            i++;
            cnt3++;
        }

        // pura array cover hona chahiye + har phase me movement hona chahiye
        return (i == n-1 && cnt1 > 0 && cnt2 > 0 && cnt3 > 0);
    }
};
