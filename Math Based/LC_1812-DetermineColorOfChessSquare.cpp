// TC : O(1) , SC : O(1)
class Solution {
public:
    bool squareIsWhite(string coordinates) {
        int first = coordinates[0]-'a'+1 ;
        int second = coordinates[1] ;
        return ( first+second )%2 != 0 ;
    }
};