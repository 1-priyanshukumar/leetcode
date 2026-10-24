
class Solution {
public:
    int countDaysTogether(string arriveAlice, string leaveAlice,
                          string arriveBob, string leaveBob) {

        int monthDays[] = {
            0, 31, 28, 31, 30, 31, 30,
            31, 31, 30, 31, 30, 31
        };

        auto convert = [&](string date) {
            int month = stoi(date.substr(0, 2));
            int day = stoi(date.substr(3, 2));

            for (int i = 1; i < month; i++) {
                day += monthDays[i];
            }

            return day;
        };

        int startAlice = convert(arriveAlice);
        int endAlice = convert(leaveAlice);

        int startBob = convert(arriveBob);
        int endBob = convert(leaveBob);

        int start = max(startAlice, startBob);
        int end = min(endAlice, endBob);

        return max(0, end - start + 1);
    }
};
