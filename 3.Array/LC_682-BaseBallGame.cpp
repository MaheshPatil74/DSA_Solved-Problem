// Approach 2 : Chatgpt
// TC==>> (N) ; SC ==>> (N)
class Solution {
public:
    int calPoints(vector<string>& operations) {
        vector<int> st;

        for (string op : operations) {
            if (op == "C") {
                st.pop_back();
            }
            else if (op == "D") {
                st.push_back(2 * st.back());
            }
            else if (op == "+") {
                int n = st.size();
                st.push_back(st[n-1] + st[n-2]);
            }
            else {
                st.push_back(stoi(op));
            }
        }

        int sum = 0;
        for (int x : st)
            sum += x;
        return sum;
    }
};


// Approach 1 : OWN
// TC==>> (N) ; SC ==>> (N)
class Solution {
public:
    int calPoints(vector<string>& operations) {
        int n = operations.size() ;
        vector<int> ans(n) ;
        int j = 0 ;
        for( int i = 0 ; i<n ; i++ ){
            string element = operations[i] ;

            if( element == "C" ){
                j-- ;
            }
            else if( element == "D"){
                ans[j] = 2*ans[j-1] ;
                j++ ;
            }
            else if( element == "+" ){
                ans[j] = ans[j-1] + ans[j-2] ;
                j++;
            }
            else{
                ans[j] = stoi(element) ;
                j++ ;
            }
        }

        int sum = 0 ;
        for( int i = 0 ; i<j ; i++ )
            sum += ans[i] ;
        return sum ;
    }
};