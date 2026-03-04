// answer of Question
#include<stack>
// Approach 1 : using extra stack and array
vector<int> nextSmallerElement(vector<int> &arr, int n){
    stack<int> s ;
    s.push(-1) ;
    vector<int> ans(n) ;
    for( int i = n-1 ; i>=0 ; i-- ){
        int curr = arr[i] ;
        while( s.top() >= curr )
            s.pop() ;

        // ans is stack ka top 
        ans[i] = s.top() ;
        s.push(curr) ;
    }
    return ans ;    
}

// Approach 2 : using only stack
#include<stack>
vector<int> nextSmallerElement(vector<int> &arr, int n){
    stack<int> s ;
    s.push(-1) ;
    for( int i = n-1 ; i>=0 ; i-- ){
        int curr = arr[i] ;
        while( s.top() >= curr )
            s.pop() ;
        arr[i] = s.top() ;
        s.push(curr) ;
    }
    return arr ;
}

// Logic for Previous Smaller element 
vector<int> prevSmallerElement(vector<int> &arr, int n){
    stack<int> s ;
    s.push(-1) ;
    vector<int> ans(n) ;
    for( int i = 0 ; i<n ; i++ ){
        int curr = arr[i] ;
        while( s.top() >= curr )
            s.pop() ;
        // ans is stack ka top 
        ans[i] = s.top() ;
        s.push(curr) ;
    }
    return ans ;    
}