// Approach 2 : Basic math 
// TC : O( 1 )
class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        long long maxByWeight = maxWeight / w ;
        long long maxBySpace = (long long)n*n ;
        return min( maxByWeight , maxBySpace );
    }
};


// Approach 1 : Using Binary Search Logic 
// TC : O( Log(N*N) )
class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        int totalCell = n*n ;

        int maxi = 0 ;

        int left = 1 ; 
        int right = totalCell ;

        while( left <= right ){
            int mid = left + (right-left)/2 ;
            long long weight = 1LL * mid * w ;

            if( weight <= maxWeight ){
                maxi = mid ;
                left = mid + 1;
            }
            else
                right = mid-1 ;
        }
        return maxi ;
    }
};