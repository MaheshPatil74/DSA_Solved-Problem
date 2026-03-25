// Approach 2 : sorting
// TC : O(N*LogN) , SC : O(1)
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        sort( tasks.begin() , tasks.end() );
        int n = tasks.size() ;
        int rounds = 0 ;

        int i = 0 ;
        while( i<n ){
            int val = tasks[i] ;
            int count = 0 ;
            while( i<n && tasks[i] == val ){
                count++ ;
                i++ ;
            }

            if( count == 1 )
                return -1 ;
            rounds += (count+2)/3 ;
        }
        return rounds ;
    }
};


// Approach 1 : using hashmap
// TC : O(N) , SC : O(N)
class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        unordered_map<int,int> mp ;
        for( int task : tasks )
            mp[task]++ ;
        
        int rounds = 0 ;
        for( auto it : mp ){
            int count = it.second ;
            if( count==1 )
                return -1 ;
            rounds += ( count+2)/3 ;
        }
        return rounds ;
    }
};