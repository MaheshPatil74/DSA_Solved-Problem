class Solution {
public:
    double angleClock(int hour, int minutes) {
        double first = (30 * hour)%360 ;
        double second = minutes*5.5 ;

        double oneAngle = abs(second-first) ;
        double secondAngle = 360-oneAngle ;

        return min(oneAngle,secondAngle) ;
    }
};