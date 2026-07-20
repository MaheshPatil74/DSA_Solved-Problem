// TC : O(N) , SC : O(N)
class Solution {
public:
    vector<int> rotateElements(vector<int>& nums, int k) {
        vector<int> temp ;
        for( int i : nums )
            if( i >= 0 )
                temp.push_back(i) ;

        int n = temp.size() ;
        if( n <= 1 )
            return nums ;

        k = k%n ;
        reverse(temp.begin() , temp.end());
        reverse(temp.begin() , temp.begin()+n-k ) ;
        reverse(temp.begin()+n-k , temp.end() ) ;

        int index = 0 ;
        for( int i = 0 ; i<nums.size() ; i++ )
            if( nums[i] >= 0 )
                nums[i] = temp[index++] ;

        return nums ;
    }
};