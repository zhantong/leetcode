class Solution {
public:
    string longestCommonPrefix(vector<string> &strs) {
        if (strs.empty()) {
            return "";
        }
        string firstStr = strs[0];
        int commonIndex = 0;
        while (true) {
            for (string &str : strs) {
                if (str.size() == commonIndex || str[commonIndex] != firstStr[commonIndex]) {
                    return firstStr.substr(0, commonIndex);
                }
            }
            commonIndex++;
        }
    }
};