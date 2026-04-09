// TC : O( n ) , SC : O(1)
class Solution {
public:
    vector<int> decimalRepresentation(int n) {
        vector<int> ans ;

        long long place = 1 ;
        while( n > 0 ){
            int digit = n%10 ;
            if( digit != 0 ){
                ans.push_back( digit * place) ;
            }
            place *= 10 ;
            n /= 10 ;
        }

        reverse( ans.begin() , ans.end() ) ;
        return ans ;
    }
};