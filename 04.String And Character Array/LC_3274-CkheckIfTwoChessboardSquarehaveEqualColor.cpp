// Approach 2 : suggested assumption
// TC : O(1) , SC : O(1)
class Solution {
private :
    int detectColor( string& word ){
        int first = word[0] - 'a' ;
        int second = word[1] - '0' ;
        return (first+second)%2 ;
    }
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        return ( detectColor( coordinate1 ) == detectColor( coordinate2 ) ) ;
    }
};


// Approach 1 : slight risky assumption
// TC : O(1) , SC : O(1)
class Solution {
private :
    char detectColor( string& word ){
        // if both odd or both even then black else white
        // Assumption 'a' == 1 , 'b' == 2 , and so on
        // Assumption '1' == 1 , '2' == 2 , and so on
        int first = word[0] - '`' ;
        int second = word[1] - '0' ;

        return (first&1) == (second&1) ? 'b' : 'w' ;
    }
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        char color1 = detectColor( coordinate1 );
        char color2 = detectColor( coordinate2 ); 
        return ( color1 == color2 ) ;
    }
};