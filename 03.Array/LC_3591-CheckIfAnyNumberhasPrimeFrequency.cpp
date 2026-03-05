// Time: O(n + 101√101) ≈ O(n)
// Space: O(101) ≈ O(1)
class Solution {
public:
    bool checkPrimeFrequency(vector<int>& nums) {
        vector<int> freq(101,0);

        for(int x : nums)
            freq[x]++;

        for(int f : freq){
            if(f > 1){
                bool prime = true;
                for(int i = 2; i*i <= f; i++){
                    if(f % i == 0){
                        prime = false;
                        break;
                    }
                }
                if(prime) return true;
            }
        }

        return false;
    }
};