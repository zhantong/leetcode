class Solution {
public:
    vector<string> addOperators(string num, int target) {
        class Utils {
        public:
            void
            backTrace(string &num, int target, int i, string current, vector<string> &result, long value, long prev) {
                if (i == num.length()) {
                    if (value == target) {
                        result.push_back(current);
                    }
                    return;
                }
                for (int j = i; j < num.length(); j++) {
                    if (j != i && num[i] == '0') {
                        break;
                    }
                    string nowInStr = num.substr(i, j + 1 - i);
                    long nowInInt = stol(nowInStr);
                    if (i == 0) {
                        backTrace(num, target, j + 1, nowInStr, result, nowInInt, nowInInt);
                    } else {
                        backTrace(num, target, j + 1, current + "+" + nowInStr, result, value + nowInInt, nowInInt);
                        backTrace(num, target, j + 1, current + "-" + nowInStr, result, value - nowInInt, -nowInInt);
                        backTrace(num, target, j + 1, current + "*" + nowInStr, result, value - prev + prev * nowInInt,
                                  prev * nowInInt);
                    }
                }
            }
        };
        Utils utils;
        vector<string> result;
        string temp = "";
        utils.backTrace(num, target, 0, temp, result, 0, 0);
        return result;
    }
};