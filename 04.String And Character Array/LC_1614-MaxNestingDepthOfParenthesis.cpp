// TC : O(N) , SC : O(1)
class Solution {
public:
    int maxDepth(string s) {
        int maxiDepth = 0 ;
        int currDepth = 0 ;

        for( char ch : s ){
            if( ch == '(' ){
                currDepth++ ;
                maxiDepth = max( maxiDepth , currDepth ) ;
            }
            else if( ch == ')' ){
                currDepth-- ;
            }
        }

        return maxiDepth ;
    }
};