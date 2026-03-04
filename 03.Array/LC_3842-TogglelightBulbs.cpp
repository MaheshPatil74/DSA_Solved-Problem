// Approach 1 :
// TC : O(N) , SC : O(1)
class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        if(bulbs.empty()) 
            return {};

        vector<int> ans ;
        vector<bool> isOn(101,false);

        for( int i = 0 ; i<bulbs.size() ; i++ ){
            int bulb = bulbs[i] ;
            isOn[bulb] = !isOn[bulb] ;
        }

        for( int i = 1 ; i<=100 ; i++ )
            if( isOn[i] )
                ans.push_back(i);

        return ans ;
    }
};