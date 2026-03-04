class Solution {
public:
    int finalValueAfterOperations(vector<string>& operations) {
        int val = 0 ;
        for( string temp : operations ){
            if( temp[1] == '+' )
                val++ ;
            else
                val-- ; 
        }
        return val ;
    }
};