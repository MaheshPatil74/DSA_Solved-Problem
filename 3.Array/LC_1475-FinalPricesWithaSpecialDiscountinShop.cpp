// Approach 2 : using stack     
// TC : O(N)
// SC : O(N)
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int> st;

        for(int i = 0; i < prices.size(); i++) {

            while(!st.empty() && prices[i] <= prices[st.top()]) {
                prices[st.top()] -= prices[i];
                st.pop();
            }

            st.push(i);
        }

        return prices;
    }
};


// Approach 1 :
// TC : O(N*N)
// SC : O(1)
class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        
        for( int i = 0 ; i+1<prices.size() ; i++ ){
            for( int j = i+1 ; j<prices.size() ; j++ ){
                if( prices[j] <= prices[i] ){
                    prices[i] -= prices[j] ;
                    break ;
                }
            }
        }
        return prices ;
    }
};