// Approach 3 : Optimal Approach (Frequency array)
// TC : O(N) , SC : O(101) == O(1) according to constraint
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int freq[101] = {0};
        int count = 0;
        for(int num : nums){
            if(num - k >= 0)
                count += freq[num - k];
            if(num + k <= 100)
                count += freq[num + k];   
            freq[num]++;
        }
        return count;
    }
};


// Approach 2: Optimal Approach (Hash Map)
// TC : O(N) , SC : O(N)
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int count = 0;
        for(int num : nums){
            count += freq[num - k];
            count += freq[num + k];
            freq[num]++;
        }      
        return count;
    }
};




// Approach 1: Brute force
// TC : O(N*N) , SC : O(1)
class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        int count = 0 ;
        for( int i = 0 ; i<nums.size()-1 ; i++ )
            for( int j = i+1 ; j<nums.size() ; j++ )
                if( abs(nums[i] - nums[j]) == k )
                    count++ ;
        return count ;
    }
};