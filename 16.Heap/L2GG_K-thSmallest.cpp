// User function template for C++

class Solution {
  public:
    // arr : given array
    // k : find kth smallest element and return using this function
    int kthSmallest(vector<int> &arr, int k) {
        // code here
        int n = arr.size() ;
        
        priority_queue<int> pq ;
        
        //step 1 
        for(int i = 0 ; i<k ; i++ ){
            pq.push( arr[i] ) ;
        }
        
        //step 2 
        for( int i = k ; i<n ; i++ ){
            if( arr[i] < pq.top() ){
                pq.pop() ;
                pq.push(arr[i]) ;
            }
        }
        
        int ans = pq.top() ;
        return ans ;
    }
};