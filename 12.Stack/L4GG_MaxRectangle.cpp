#include<stack>

class Solution {
  private:
    vector<int> nextSmallerElement(vector<int> arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=n-1; i>=0 ; i--) {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
                s.pop();
            //ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans;
    }
    
    vector<int> prevSmallerElement(vector<int> arr, int n) {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=0; i<n; i++) {
            int curr = arr[i];
            while(s.top() != -1 && arr[s.top()] >= curr)
                s.pop();
            //ans is stack ka top
            ans[i] = s.top();
            s.push(i);
        }
        return ans; 
    }    
    
  
  
  int largestRectangleArea(vector<int>& heights, int n) {
        //int n= heights.size();
        
        vector<int> next(n);
        next = nextSmallerElement(heights, n);
            
        vector<int> prev(n);
        prev = prevSmallerElement(heights, n);
        
        int area = INT_MIN;
        for(int i=0; i<n; i++) {
            int l = heights[i];
            
            if(next[i] == -1) 
                next[i] = n;
            int b = next[i] - prev[i] - 1;
            int newArea = l*b;
            area = max(area, newArea);
        }
        return area;
    }
  
  
  public:
    int maxArea(vector<vector<int>> &mat) {
        // code here
        // Compute area of first row
        int n = mat.size() ;
        int m = mat[0].size() ;
    
        int area = largestRectangleArea( mat[0] , m ) ;
        
        for(int i = 1; i<n; i++) {
            for(int j = 0; j<m; j++) {
                //row udpate: by adding previous row's value
                if(mat[i][j] != 0)
                    mat[i][j] = mat[i][j] + mat[i-1][j];
                else
                    mat[i][j] = 0;
            }
            
            //entire row is updated now
            area = max(area, largestRectangleArea(mat[i],m)); 
        }
        return area;
    }
};