// TC = O(n) & SC = O(n)
class Solution {
  private:
    bool knows(int a , int b , vector<vector<int> >& mat , int n ){
        return (mat[a][b] == 1) ;
    }
  public:
    int celebrity(vector<vector<int> >& mat) {
        int n = mat.size() ;
        //step1: push all element in stack
        stack<int> s ;
        for(int i = 0 ; i<n ; i++ )
            s.push(i) ;
        
        //step2: get 2 elements and compare them
        while( s.size() > 1 ){
            int a = s.top() ;
            s.pop() ;
            int b = s.top() ;
            s.pop() ;
            
            if( knows( a , b , mat , n ) )
                s.push(b) ;
            else
                s.push(a) ;    
        }
        int ans = s.top() ;

        //step3: single element in stack is potential celebrity ,so verify it
        int zeroCount = 0 ;
        for( int i = 0 ; i<n ; i++ )
            if( mat[ans][i] == 0 )
                zeroCount++ ;
        
        //all zeroes    
        if( zeroCount != n-1 )
            return -1 ;
        
        //column check
        int oneCount = 0 ;
        for( int i = 0 ; i<n ; i++ )
            if( mat[i][ans] == 1 )
                oneCount++ ;
          
        if( oneCount != n )
            return -1 ;
        
        return ans ;
    }
};  