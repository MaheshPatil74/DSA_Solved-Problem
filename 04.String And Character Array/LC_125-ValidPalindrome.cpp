// Approach 3 : Single Pass ==>> TC : O(N) , SC : O(1)
class Solution {
public:
    bool isValid( char c ){
        return  ( c>='a' && c<='z' ) || ( c>='A' && c<='Z' ) || ( c>='0' && c<='9' ) ;
    }

    bool isPalindrome(string s) {
        int n = s.size() ;
        int left = 0 , right = n-1 ;

        while( left < right ){
            while( left < right && !isValid( s[left] ) )
                left++ ;

            while( left < right && !isValid( s[right] ) )
                right-- ;
            
            if( left<right && s[left] >= 'A' && s[left]<='Z' )
                s[left] = s[left]-'A'+'a' ;

            if( left<right && s[right] >= 'A' && s[right]<='Z' )
                s[right] = s[right]-'A'+'a' ;

            if( left < right && s[left] != s[right] )
                return false ;

            left++ ;
            right-- ;
        }
        return true ;
    }
};


// Approach 2 : two Pass => TC : O(N) , SC : O(N)
class Solution {
public:
    bool isPalindrome(string s) {
        vector<char> ans;
        for (int i = 0; s[i] != '\0'; i++) {
            if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >= '0' && s[i] <= '9'))
                if (s[i] >= 'A' && s[i] <= 'Z') 
                    s[i] = s[i] + 32; // convert uppercase to lowercase
                ans.push_back(s[i]);
        }

        int start = 0 , end = ans.size() - 1 ;
        while(start<end){
            if( ans[start] != ans[end] )
                return 0 ;
            start++ ;
            end-- ;
        }
        return 1 ;
    }
};

// Approach 1 : Three Pass ==>> TC : O(N) , SC : O(N)
class Solution {
    private: 
        bool valid(char ch){
            return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z') || (ch >= '0' && ch <= '9'));
        }
    
        char toLower(char ch){
            if( (ch>='a' && ch<='z') || (ch>='0' && ch<='9') )
                return ch ;
            else{
                char temp = ch - 'A' + 'a' ;
                return temp ;
            }
        }
            
        bool checkPalindrome(string a) {
            int start = 0 , end = a.length() - 1 ;
        
            while(start<=end){
                if( a[start] != a[end] )
                    return 0 ;
                start++ ;
                end-- ;
            }
            return 1 ;
        }
    public:
        bool isPalindrome(string s){
            //faltu character hatado
            string temp = "" ;

            for(int j = 0 ; j<s.length() ; j++ )
                if ( valid(s[j]) ) 
                    temp.push_back(s[j]) ;
    
            for(int j = 0 ; j<temp.length() ; j++ )
                temp[j] = toLower( temp[j] ) ;
    
            return checkPalindrome(temp) ;
        }
    };