// Apprch 2 ==>> Unordered Set  (Hashinhg)
// time Complexity  : O( n )    
// space Complexity : O( n )
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> st;

        for (int x : nums) {
            if (st.count(x))
                return true;
            st.insert(x);
        }
        return false;
    }
};


// Apprch 1 ==>> Sorting
// time Complexity  : O( n log n )
// space Complexity : O( 1 )
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        if( nums.empty() )
            return false ;

        sort( nums.begin() , nums.end() );

        for( int i = 0 ; i<nums.size()-1 ; i++ )
            if( nums[i] == nums[i+1] )
                return true ;

        return false ;
    }
};