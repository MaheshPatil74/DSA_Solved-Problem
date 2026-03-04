// Approach 2 : Same as 1 slight change only
// TC = O(N) and SC = O(1)
class Solution {
public:
    string largestGoodInteger(string nums) {
        char best = 0;
        for(int i = 0; i + 2 < nums.size(); i++) 
            if(nums[i] == nums[i+1] && nums[i] == nums[i+2]) 
                best = max(best, nums[i]);

        return best ? string(3, best) : "";
    }
};


// Approach 1 : My Own 
// TC = O(N) and SC = O(1)
class Solution {
public:
    string largestGoodInteger(string nums) {
        
        char ans = '\0' ;
        for( int i = 0 ; i+2<nums.length() ; i++ )
            if( nums[i] == nums[i+1] && nums[i] == nums[i+2] )
                ans = max( ans , nums[i] ) ; 

        string finalAns = "" ;
        if( ans != '\0' ){
            finalAns.push_back(ans) ;
            finalAns.push_back(ans) ;
            finalAns.push_back(ans) ;
        }
        return finalAns ;
    }
};