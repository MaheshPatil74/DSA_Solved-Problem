// Approach 2 :
// TC : O(N) , SC : O(N)
class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<string> st;
        int n = word.size();

        for(int i = 0; i < n; i++) {
            if(isdigit(word[i])) {
                string num = "";

                // build number
                while(i < n && isdigit(word[i])) {
                    num += word[i];
                    i++;
                }

                // remove leading zeros
                int j = 0;
                while(j < num.size() && num[j] == '0') j++;

                num = num.substr(j);

                // if empty means "0"
                if(num == "") num = "0";

                st.insert(num);
            }
        }
        return st.size();
    }
};

// Approach 1 : Number become exceeded Range of Integer , so answer should be of string
// TC : O(N) , SC : O(N)
class Solution {
public:
    int numDifferentIntegers(string word) {
        unordered_set<int> st ;
        int i = 0 ;
        while( i<word.size() ){
            if( isdigit(word[i]) ){
                int num = 0 ;
                while( i<word.size() && isdigit(word[i]) ){
                    num = num*10 + ( word[i]-'0' ) ;
                    i++ ;
                }
                st.insert(num) ;;
            }
            else
                i++ ;
        }
        return st.size() ;
    }
};