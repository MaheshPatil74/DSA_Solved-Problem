// TC : O( N + 100Log100 ) == O(N) , SC : O(1)
class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        vector<int> freq(101,0) ;

        for( int num : nums )
            freq[num]++ ;

        sort( freq.begin() , freq.end() ) ;

        int lastFreq = freq[100] ;
        int sum = lastFreq ;
        for( int i = 99 ; i>=0 ; i-- ){
            if( freq[i] != freq[100] )
                break ;
            else
                sum += lastFreq ;
        }
        return sum ;
    }
};