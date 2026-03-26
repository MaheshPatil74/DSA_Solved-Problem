class Solution {
public:
    string interpret(string command) {
        string ans = "" ;

        int i = 0 ;
        while( i<command.size() ){
            if( command[i] == 'G' )
                ans.push_back('G');
            else if( command[i] == '(' ){
                i++ ;
                if( command[i] == ')' ){
                    ans.push_back('o') ;
                }
                else{
                    ans += "al" ;
                    i += 2 ;
                }
            }
            i++ ;
        }
        return ans ;
    }
};