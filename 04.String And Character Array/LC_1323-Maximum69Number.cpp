// Approach 2 : Math base , No string
// Traverse digits from right → left and remember last position of 6, then change it.
// TC : O(LogN) , SC : O(1)
class Solution {
public:
    int maximum69Number (int num) {
        int temp = num ;
        int pos = 0 ;
        int leftSixPos = -1 ;

        while( temp > 0 ){
            if( temp%10 == 6 )
                leftSixPos = pos ;
            temp /= 10 ;
            pos++ ;
        }

        if( leftSixPos == -1 )
            return num ;
        return num + 3*pow(10,leftSixPos) ;
    }
};

// Approach 1 : change first '6' from left to '9'
// TC : O(N) , SC : O(N)
class Solution {
public:
    int maximum69Number (int num) {
        string s = to_string(num) ;
        for( int i = 0 ; i<s.length() ; i++ ){
            if( s[i] == '6' ){
                s[i] = '9';
                break ;
            }
        }
        return stoi(s) ;
    }
}; 