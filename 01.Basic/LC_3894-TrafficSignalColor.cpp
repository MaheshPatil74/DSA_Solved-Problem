// TC : O(1) , SC : O(1)
class Solution {
public:
    string trafficSignal(int timer) {
        if( timer == 0 )
            return "Green" ;
        else if( timer == 30 )
            return "Orange" ;
        else if( timer <= 90 && timer>30 )
            return "Red" ;
        else
            return "Invalid" ;
    }
};