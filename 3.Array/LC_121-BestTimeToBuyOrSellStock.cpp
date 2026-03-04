// Approach 4 : Shradha mam ( consider each day as best selling day)
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxProfit = 0 ;
        int bestBuy = prices[0] ;

        for( int i = 1 ; i<prices.size() ; i++ ){
            if( prices[i] > bestBuy )
                maxProfit = max( maxProfit , prices[i] - bestBuy ) ;

            bestBuy = min(bestBuy , prices[i]) ;
        }

        return maxProfit ;
    }
};


// Approach 3 : One Pass
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for (int price : prices) {
            minPrice = min(minPrice, price);
            maxProfit = max(maxProfit, price - minPrice);
        }
        return maxProfit;
    }
};



// Approach 2 : Two Pointer
// Time Complexity: O(n)
// Space Complexity: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int left = 0 ;
        int right = 1 ;
        int maxProfit = 0 ;

        while( right < prices.size() ){
            if( prices[left] < prices[right] ){
                int tempProfit = prices[right] - prices[left] ;
                maxProfit = max( maxProfit , tempProfit) ;
            }
            else
                left = right ;
            
            right++ ;
        } 
        return maxProfit ;
    }
};


// Approach 1: Brute Force
// Time Complexity: O(n^2) space Complexity: O(1)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int tempProfit = INT_MIN ;
        for( int i = 0 ; i<prices.size()-1 ; i++ )
            for( int j = i+1 ; j<prices.size() ; j++ )
                tempProfit = max( tempProfit , prices[j] - prices[i] ) ;

        return ( tempProfit < 0 ) ? 0 : tempProfit ;
    }
};