// Approach 2 : 
// TC : O(N*M) , SC : O(N+M)
class Solution {
public:
    string multiply(string num1, string num2) {
        if(num1 == "0" || num2 == "0")
            return "0";

        int n = num1.size();
        int m = num2.size();

        vector<int> result(n + m, 0);

        for(int i = n - 1; i >= 0; i--){
            for(int j = m - 1; j >= 0; j--){
                int mul = (num1[i] - '0') * (num2[j] - '0');

                int sum = mul + result[i + j + 1];

                result[i + j + 1] = sum % 10;
                result[i + j] += sum / 10;
            }
        }

        string ans = "";

        for(int num : result){
            if(!(ans.empty() && num == 0))
                ans.push_back(num + '0');
        }

        return ans;
    }
};

// Approach 1 : Wrong answer integer overflow
// TC : O(N) , SC : O(N)
class Solution {
private :
    int stringToInteger( string num ){
        long long int ans = 0 ;
        for( int i = 0 ; i<num.size() ; i++ )
            ans = ( ans * 10 ) + ( num[i] - '0' );
        return ans ;
    }
public:
    string multiply(string num1, string num2) {
        if( num1 == "0" || num2 == "0" )
            return "0";

        long int first = stringToInteger(num1) ;
        long int second = stringToInteger(num2) ;
        long long int mul = first*second ;
        string ans ;
        while( mul > 0 ){
            ans.push_back( (mul % 10)+'0' );
            mul /= 10 ;
        }

        int left = 0 ;
        int right = ans.size() - 1 ;
        while( left < right )
            swap( ans[left++] , ans[right--] ) ;

        return ans ;
    }
};