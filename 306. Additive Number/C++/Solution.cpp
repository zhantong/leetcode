class Solution {
public:
    bool isAdditiveNumber(string num) {
        class Utils {
        public:
            bool isAdditive(int second, int third, string &num) {
                if (num[second] == '0' && third - second > 1) {
                    return false;
                }
                int first = 0;
                while (third < num.length()) {
                    long a = stol(num.substr(first, second - first));
                    long b = stol(num.substr(second, third - second));
                    string theSum = to_string(a + b);
                    if (!num.substr(third).find(theSum) == 0) {
                        return false;
                    }
                    first = second;
                    second = third;
                    third += theSum.length();
                }
                return true;
            }
        };
        Utils utils;
        for (int second = 1; second < num.length(); second++) {
            if (num[0] == '0' && second > 1) {
                continue;
            }
            for (int third = second + 1; third < num.length(); third++) {
                if (second <= num.length() - third && third - second <= num.length() - third) {
                    if (utils.isAdditive(second, third, num)) {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};