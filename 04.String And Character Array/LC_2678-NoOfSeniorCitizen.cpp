// Time Complexity: O(N) , Space Complexity: O(1)
class Solution {
public:
    int countSeniors(vector<string>& details) {
        int count = 0 ;
        for( int i = 0 ; i<details.size() ; i++ ){
            int digit1 = details[i][11] - '0' ;
            int digit2 = details[i][12] - '0' ;
            int age = (digit1*10) + digit2 ;
            if( age>60 )
                count++ ;
        }
        return count ;
    }
};