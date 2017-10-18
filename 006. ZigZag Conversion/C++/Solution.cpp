class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> rows(numRows, "");
        int index = 0;
        while (index < s.length()) {
            for (int i = 0; i < numRows && index < s.length(); i++) {
                rows[i] += s[index];
                index++;
            }
            for (int i = numRows - 2; i > 0 && index < s.length(); i--) {
                rows[i] += s[index];
                index++;
            }
        }
        string result = "";
        for (auto &row : rows) {
            result += row;
        }
        return result;
    }
};