// TC : O(N) , SC : O(1)
class Solution {
public:
    double average(vector<int>& salary) {
        
        double sum = 0 ;
        int maxSalary = INT_MIN ;
        int minSalary = INT_MAX ;
        for( int temp : salary ){
            minSalary = min( minSalary , temp );
            maxSalary = max( maxSalary , temp );
            sum += temp ;
        }
        sum = sum - minSalary - maxSalary ;
        return ( sum / (salary.size()-2) ) ;
    }
};