// Approach 1:(ChatGPT) Dynamic Programming
// Time Complexity: O(n)    
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            ans[i] = ans[i / 2] + (i % 2);
        }
        return ans;
    }
};

// Approach 2: (My Own) 
// Time Complexity: O(n)
class Solution {
public:
    vector<int> countBits(int n) {

        vector<int> ans(n+1);

        if( n >= 0 )
            ans[0] = 0 ;

        if( n >= 1 )
            ans[1] = 1 ;

        if( n >= 2 )
            ans[2] = 1 ;
    
        int x = 2 ;
        for( int i = 3 ; i<=n ; i++ ){
            int rem = i%x ;
            if( rem==0 ){
                ans[i] = 1 ;
                x = x*2 ;
            }
            else{
                ans[i] = ans[rem] + 1 ;
            }
        }
        return ans ;
    }
};