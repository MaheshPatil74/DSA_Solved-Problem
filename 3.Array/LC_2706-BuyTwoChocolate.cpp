// Approach 2
// TC : O( N )
class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        
        int min1 = INT_MAX ;    //first minimum
        int min2 = INT_MAX ;    //second minimum

        for( int temp : prices ){
            if( temp<min1 ){
                min2 = min1 ;
                min1 = temp ;
            }
            else if( temp<min2 )
                min2 = temp ;
        }
        int ans = money - ( min1 + min2 ) ;
        return (ans<0) ? money : ans ;
    }
};

// Approach 1
// TC : O( NLogN)
class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        if(prices.size() <=1)
            return money ;

        sort(prices.begin(), prices.end());

        int ans = money - ( prices[0] + prices[1] ) ;
        return (ans<0) ? money : ans ;
    }
};