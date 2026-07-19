// TC : O(1) , SC : O(1)
class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        bool startParity = ( start[0] + start[1] ) % 2 ;
        bool targetParity = ( target[0] + target[1] ) % 2 ;
        return startParity == targetParity ;
    }
};