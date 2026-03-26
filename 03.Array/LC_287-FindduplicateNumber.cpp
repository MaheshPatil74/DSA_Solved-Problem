// Approach 3 : Optimal Approach (Floyd’s Cycle Detection)
// But question say used constant space and do not modify array
// TC : O(N) , SC : O(N)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int slow = nums[0];
        int fast = nums[0];

        // Step 1: Detect cycle
        do {
            slow = nums[slow];
            fast = nums[nums[fast]];
        } while(slow != fast);

        // Step 2: Find cycle start
        slow = nums[0];
        while(slow != fast) {
            slow = nums[slow];
            fast = nums[fast];
        }

        return slow;
    }
};

// Approach 2 : used frequncy
// But question say used constant space and do not modify array
// TC : O(N) , SC : O(N)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        unordered_set<int> set ;
        for( int num : nums ){
            if( set.count( num ) )
                return num ;
            set.insert(num) ;
        }
        return -1 ;
    }
};


// Approach 1 : sort and compare current with next element
// But question say do not modify array
// TC : O(N*LogN) , SC : O(1)
class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        sort( nums.begin() , nums.end() );
        for( int i = 0 ; i<nums.size()-1 ; i++ )
            if( nums[i] == nums[i+1] )
                return nums[i] ;
        return 0 ;
    }
};