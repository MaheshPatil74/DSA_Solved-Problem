// Approach 2 : Optimised
// TC : O(1) , SC : O(1)
class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int start =
            ((startTime[0]-'0')*10 + (startTime[1]-'0')) * 3600 +
            ((startTime[3]-'0')*10 + (startTime[4]-'0')) * 60 +
            ((startTime[6]-'0')*10 + (startTime[7]-'0'));

        int end =
            ((endTime[0]-'0')*10 + (endTime[1]-'0')) * 3600 +
            ((endTime[3]-'0')*10 + (endTime[4]-'0')) * 60 +
            ((endTime[6]-'0')*10 + (endTime[7]-'0'));

        return end - start;
    }
};


// Approach 1 : Using String
// TC : O(1) , SC : O(1)
class Solution {
public:
    int secondsBetweenTimes(string startTime, string endTime) {
        int h1 = stoi(startTime.substr(0,2));
        int m1 = stoi(startTime.substr(3,2));
        int s1 = stoi(startTime.substr(6,2));
        
        int h2 = stoi(endTime.substr(0,2));
        int m2 = stoi(endTime.substr(3,2));
        int s2 = stoi(endTime.substr(6,2));
        
        int start = h1*3600 + m1*60 + s1 ;
        int end = h2*3600 + m2*60 + s2 ;
        
        return end-start ;
    }
};