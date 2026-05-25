// TC : O(year-1971) == O(1) , SC : O(1)
class Solution {
public:
    bool isLeap(int y) {
        return (y % 400 == 0) || (y % 4 == 0 && y % 100 != 0);
    }

    string dayOfTheWeek(int day, int month, int year) {

        vector<string> weekDays = {"Sunday", "Monday", "Tuesday","Wednesday", "Thursday","Friday", "Saturday"};

        vector<int> prefixDaysMonth = {0,31,59,90,120,151,181,212,243,273,304,334};

        int totalOddDays = 0;

        // odd days from years
        for (int i = 1971; i < year; i++)
            totalOddDays += isLeap(i) ? 2 : 1;

        // odd days from months
        totalOddDays += prefixDaysMonth[month - 1] % 7;

        // leap year adjustment
        if (month > 2 && isLeap(year))
            totalOddDays++;

        // odd days from current date
        totalOddDays += day % 7;

        totalOddDays %= 7 ;

        // 1971-01-01 was Friday
        return weekDays[(totalOddDays + 4) % 7];
    }
};