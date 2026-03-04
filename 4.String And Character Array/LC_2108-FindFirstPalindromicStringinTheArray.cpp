// Time Complexity : O( n * m )  where n is the number of words and m is the average length of each word
// Space Complexity : O( 1 )
class Solution {
private :
    bool isPalindrome( string temp ){
        int i = 0 ;
        int j = temp.length() -  1 ;

        while( i<j ){
            if( temp[i] != temp[j] )
                return false ;
            i++ ;
            j-- ;
        }
        return true ;
    }
public:
    string firstPalindrome(vector<string>& words) {

        for( string temp : words ){
            if( isPalindrome(temp) )
                return temp ;
        }
        return "" ; 
    }
};