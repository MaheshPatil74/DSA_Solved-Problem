// TC : O(N) , SC : O(1)
class Solution {
public:
    vector<int> numberOfLines(vector<int>& widths, string s) {
        int lines = 1 ;
        int width = 0 ;
        for( char ch : s ){
            int tempWidth = widths[ ch - 'a' ] ;
            width += tempWidth ;
            if( width > 100 ){
                lines++ ;
                width = tempWidth ;
            }
        }

        return { lines , width } ;
    }
};