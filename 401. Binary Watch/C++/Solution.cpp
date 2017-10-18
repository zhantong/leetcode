class Solution {
public:
    vector<string> readBinaryWatch(int num) {
        class Utils {
        public:
            void getCombination(int length, int numOnes, int base, vector<int> &pool) {
                if (numOnes == 0) {
                    pool.push_back(base);
                    return;
                }
                if (length == 0 || length < numOnes) {
                    return;
                }
                getCombination(length - 1, numOnes - 1, base + (1 << (length - 1)), pool);
                getCombination(length - 1, numOnes, base, pool);
            }
        };
        Utils utils;
        vector<string> result;
        for (int onesHour = 0; onesHour <= num; onesHour++) {
            int onesMinute = num - onesHour;
            vector<int> hours;
            vector<int> minutes;
            utils.getCombination(4, onesHour, 0, hours);
            utils.getCombination(6, onesMinute, 0, minutes);
            for (int hour : hours) {
                if (hour > 11) {
                    continue;
                }
                for (int minute : minutes) {
                    if (minute > 59) {
                        continue;
                    }
                    if (minute > 9) {
                        result.push_back(to_string(hour) + ":" + to_string(minute));
                    } else {
                        result.push_back(to_string(hour) + ":0" + to_string(minute));
                    }
                }
            }
        }
        return result;
    }
};