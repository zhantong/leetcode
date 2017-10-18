class Solution {
public:
    bool isSubsequence(string s, string t) {
        if (s.empty()) {
            return true;
        }
        int indexS = 0;
        for (auto item : t) {
            if (item == s[indexS]) {
                if (indexS == s.length() - 1) {
                    return true;
                }
                indexS++;
            }
        }
        return false;
    }
};