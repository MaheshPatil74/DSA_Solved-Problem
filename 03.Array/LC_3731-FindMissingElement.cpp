// Approach 2 : frequency vector
// TC : O(N) , SC : O(1)
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        vector<int> V(101,false) ;
        int minVal = INT_MAX , maxVal = INT_MIN ;
        for( int i = 0 ; i<nums.size() ; i++ ){
            minVal = min( minVal , nums[i] );
            maxVal = max( maxVal , nums[i] );
            V[ nums[i] ] = true ;
        }

        vector<int> res ;
        for( int i = minVal ; i<= maxVal ; i++ ){
            if( !V[i] )
                res.push_back( i ) ;
        }
        return res ;
    }
};


// Approach 1 : Sorting
// TC : O(N*LogN) , SC : O(1)
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort( nums.begin() , nums.end() ) ;
        vector<int> res ;

        int i = 0 , counter = nums[0];
        while( i<nums.size() ){
            if( nums[i] != counter )
                res.push_back( counter ) ;
            else
                i++ ;
            counter++ ;
        }
        return res ;
    }
};