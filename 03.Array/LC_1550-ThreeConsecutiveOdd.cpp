// Approach 2 : maintain counter
// TC : O(N) , SC : O(1)
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        int count = 0 ;
        for( int num : arr ){
            if( num%2 ){
                count++ ;
                if( count == 3 )
                    return true ;
            }
            else
                count = 0 ;
        }
        return false ;
    }
};



// Approach 1 : Check prev, current, next for odd
// TC : O(N) , SC : O(1)
class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        for( int i = 1 ; i+1<arr.size() ; i++ )
            if( arr[i-1]%2 && arr[i]%2 && arr[i+1]%2 )
                return true ;
        return false ;
    }
};