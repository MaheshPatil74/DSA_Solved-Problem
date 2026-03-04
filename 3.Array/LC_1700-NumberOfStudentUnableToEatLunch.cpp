// Same as below only for my simplyness
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int oneCount = 0 ;
        int zeroCount = 0 ;

        // count preferences
        for( int temp : students ){
            if( temp == 1 )
                oneCount++ ;
            else
                zeroCount++ ;
        }

        // process sandwitches
        for( int s : sandwiches ){
            if( s == 0 ){
                if( zeroCount == 0 )
                    break ;
                zeroCount-- ;
            }
            else{
                if( oneCount == 0 )
                    break ;
                oneCount--;
            }
        }
        return oneCount + zeroCount ;
    }
};



// TC : O(N) , SC : O(1)
class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int oneCount = 0 ;
        int zeroCount = 0 ;

        // count preferences
        for( int temp : students ){
            if( temp == 1 )
                oneCount++ ;
            else
                zeroCount++ ;
        }

        // process sandwitches
        for( int s : sandwiches ){
            if( s == 0 ){
                if( zeroCount == 0 )
                    return oneCount ;
                zeroCount-- ;
            }
            else{
                if( oneCount == 0 )
                    return zeroCount ;
                oneCount--;
            }
        }
        return 0 ;
    }
};