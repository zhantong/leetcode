class Solution {
public:
    vector<string> restoreIpAddresses(string s) {
        class Utils {
        public:
            void backTrack(string &s, vector<string> &result, string &current, int index, int count) {
                if (count > 4) {
                    return;
                }
                if (count == 4 && index == s.length()) {
                    result.push_back(current.substr(0, current.length() - 1));
                } else if (count < 4) {
                    for (int i = 0; i < 3; i++) {
                        if (index + i >= s.length()) {
                            break;
                        }
                        string sub = s.substr(index, i + 1);
                        if (stoi(sub) >= 256 || (sub[0] == '0' && sub.length() > 1)) {
                            continue;
                        }
                        string temp = current + sub + ".";
                        backTrack(s, result, temp, index + i + 1, count + 1);
                    }
                }
            }
        };
        vector<string> result;
        Utils utils;
        string temp = "";
        utils.backTrack(s, result, temp, 0, 0);
        return result;
    }
};