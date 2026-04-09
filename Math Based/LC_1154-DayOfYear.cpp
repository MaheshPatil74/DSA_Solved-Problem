// Approach 2 : slight more optimal
// TC : O(1) , SC : O(1)
class Solution {
public:
    int dayOfYear(string date) {
        int month = (date[5]-'0')*10 + (date[6]-'0') ;
        int day = (date[8]-'0')*10 + (date[9]-'0') ;
        int year = (date[0]-'0')*1000 + (date[1]-'0')*100 + (date[2]-'0')*10 + (date[3]-'0') ;

        int prefix[12] = {0,31,59,90,120,151,181,212,243,273,304,334};

        int result = prefix[month - 1] + day;

        // Leap year adjustment
        if (month > 2 && ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))) {
            result++;
        }

        return result;
    }
};


// Approach 1 : already optimal
// TC : O(1) , SC : O(1)
class Solution {
public:
    int dayOfYear(string date) {
        int month = (date[5]-'0')*10 + (date[6]-'0') ;
        int day = (date[8]-'0')*10 + (date[9]-'0') ;
        int year = (date[0]-'0')*1000 + (date[1]-'0')*100 + (date[2]-'0')*10 + (date[3]-'0') ;
        vector<int> days = {31,28,31,30,31,30,31,31,30,31,30,31};

        // Leap year check
        if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
            days[1] = 29;

        int total = 0;
        for (int i = 0; i < month - 1; i++) 
            total += days[i];

        return total + day;
    }
};