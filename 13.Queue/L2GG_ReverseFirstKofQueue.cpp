class Solution {
  public:
    queue<int> reverseFirstK(queue<int> q, int k) {
        //algo:
        // first k element stack me daaldo  and queue se hatado
        // k element stack se nikalke wapas queue me daalde 
        // fer queue k (n-k) starting k elements, wapas queue me daalde
        
        if( k>q.size() || k<0 )
            return q ;
        
        stack<int> s;
        int n = q.size() ;
        for(int i = 0 ; i<k ; i++ ){
            s.push(q.front()) ;
            q.pop() ;
        }
        while( !s.empty() ){
            q.push(s.top()) ;
            s.pop() ;
        }
        for(int i = 0 ; i<n-k ; i++ ){
            q.push(q.front()) ;
            q.pop() ;
        }
        return q ;
    }
};