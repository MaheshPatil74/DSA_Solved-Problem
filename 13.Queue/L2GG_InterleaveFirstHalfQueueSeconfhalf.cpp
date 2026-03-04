class Solution {
  public:
    queue<int> rearrangeQueue(queue<int> q) {
        stack<int> s ;
        int n = q.size() ;
        int half = n/2 ;
        
        for(int i = 0 ; i<half ; i++ ){
            s.push( q.front() ) ;
            q.pop() ;
        }
        
        while( !s.empty() ){
            q.push(s.top()) ;
            s.pop() ;
        }
        
        for(int i = 0 ; i<half ; i++ ){
            q.push( q.front() ) ;
            q.pop() ;
        }

        for(int i = 0 ; i<half ; i++ ){
            s.push( q.front() ) ;
            q.pop() ;
        }
        
        while( !s.empty() ){
            q.push( s.top() ) ;
            s.pop() ;
            q.push(q.front()) ;
            q.pop() ;
        }
        return q ;
    }
};