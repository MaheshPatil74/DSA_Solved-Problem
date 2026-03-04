class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int left = 0 ;
        int right = height.size() - 1 ;

        int area = 0 ;

        while( left<right ){
            int base = right - left ;
            int high = min( height[left] , height[right] ) ;
            int tempArea = base * high ;
            area = max( area , tempArea ) ;

            if( height[left] <= height[right] ){
                left++ ;
            }
            else{
                right-- ;
            }
        }
        return area ;
    }
};