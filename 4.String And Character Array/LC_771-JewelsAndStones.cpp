// Approach 2 : Using vector  direct ascii ==>> slight cleaner
// TC : O(N+M) , SC : O(1) // constant size vector
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        vector<bool> present(128, false);   // direct ASCII use
        for(char ch : jewels)
            present[ch] = true;

        int count = 0;
        for(char ch : stones)
            if(present[ch])
                count++;
        return count;
    }
};

// Approach 1 : Using vector use hashing
// TC : O(N+M) , SC : O(1) // constant size vector
class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        
        vector<bool> present(52,false) ;        
        //0-25 ==>> for small letter
        //26-51 ==>> for capital letter

        for( char ch : jewels ){
            if( ch>='A' && ch<='Z')
                present[ch-'A'+26] = true ;
            else
                present[ch-'a'] = true ;
        }

        int count = 0 ;
        for( char ch : stones ){
            if( ch>='A' && ch<='Z'){
                if ( present[ch-'A'+26] )
                    count++ ;
            }
            else{
                if ( present[ch-'a'] )
                    count++ ;
            }
        }
        return count ;
    }
};