// TC : O(N) , SC : O(N)
class Solution {
public:
    string minRemoveToMakeValid(string s) {
        
        string temp = "";
        int open = 0 ;
        // pass 1 : Scan left to right and remove extra ")"
        for( char ch : s ){
            if( ch == '(' ){
                open++ ;
                temp += ch ;
            }
            else if( ch == ')' ){
                if( open>0 ){
                    open-- ;
                    temp+=ch ;
                }
            }
            else{
                temp+=ch ;
            }
        }

        // pass 2 : Scan right to left and remove extra "("
        string res = "" ;
        int close = 0 ;
        for( int i = temp.size()-1 ; i>=0 ; i-- ){
            if( temp[i] == ')' ){
                close++ ;
                res += temp[i] ;
            }
            else if( temp[i] == '(' ){
                if( close>0 ){
                    close-- ;
                    res+=temp[i] ;
                }
            }
            else{
                res+= temp[i] ;
            }
        }
        reverse( res.begin() , res.end() );
        return res ;
    }
};