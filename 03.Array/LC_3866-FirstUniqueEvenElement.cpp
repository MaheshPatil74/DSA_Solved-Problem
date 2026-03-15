// Approach 2 : using map of frequency
// TC : O(N) , SC : O(N)
class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        unordered_map<int,int> freq ;
        for( int num : nums )
            freq[num]++ ;

        for( int num : nums ){
            if( num%2==0 && freq[num]==1 )
                return num ;
        }
        return -1;
    }
};


// Approach 1 : for each even element search whole array
// TC : O(N*N) , SC : O(1)
class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        
        for(int i = 0; i < nums.size(); i++){
            int currVal = nums[i];

            if(currVal % 2 == 0){
                int j = 0;

                while(j < nums.size()){
                    if(j != i && nums[j] == currVal)
                        break;
                    j++;
                }

                if(j == nums.size())
                    return currVal;
            }
        }
        return -1;
    }
};