class Solution {
public:
    int findLUSlength(vector<string> &strs) {
        class Utils {
        public:
            bool isSubsequence(string a, string b) {
                int i = 0;
                for (auto letter : b) {
                    if (letter == a[i]) {
                        i++;
                        if (i == a.length()) {
                            return true;
                        }
                    }
                }
                return false;
            }
        };
        Utils utils;
        int result = -1;
        for (int i = 0; i < strs.size(); i++) {
            bool flag = true;
            for (int j = 0; j < strs.size(); j++) {
                if (i != j && utils.isSubsequence(strs[i], strs[j])) {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                result = max(result, (int) strs[i].length());
            }
        }
        return result;
    }
};