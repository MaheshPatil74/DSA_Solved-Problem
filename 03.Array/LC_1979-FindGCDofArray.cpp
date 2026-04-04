// Approach 2 : GCD Formula (Euclidean Algorithm)
// 𝑔𝑐𝑑(𝑎,𝑏) = 𝑔𝑐𝑑 ( 𝑏 , 𝑎 mod 𝑏)
// Jab tak b = 0 nahi ho jata, tab tak repeat karo.
// TC : O(N + Log(mini) ) , SC : O(1)
class Solution {
public:
    int findGCD(vector<int>& nums) {
        int maxi = INT_MIN , mini = INT_MAX ;
        for( int num : nums ){
            maxi = max( maxi , num );
            mini = min( mini , num );
        }

        while( mini != 0 ){
            int temp = mini ;
            mini = maxi%mini ;
            maxi = temp ;
        }
        
        return maxi ;
    }
};



// Approach 1 : 
// TC : O(N + mini) , SC : O(1)
class Solution {
public:
    int findGCD(vector<int>& nums) {
        int maxi = INT_MIN , mini = INT_MAX ;
        for( int num : nums ){
            maxi = max( maxi , num );
            mini = min( mini , num );
        }

        if( maxi % mini == 0 ) 
            return mini ;

        for( int i = mini ; i>=1 ; i-- )
            if( maxi%i == 0 && mini%i==0 )
                return i ;
        return 1 ;
    }
};