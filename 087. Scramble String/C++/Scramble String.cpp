class Solution {
public:
    bool isScramble(string s1, string s2) {
        if (s1 == s2) {
            return true;
        }
        if (s1.length() != s2.length()) {
            return false;
        }
        int length = s1.length();
        vector<int> count(26, 0);
        for (int i = 0; i < length; i++) {
            count[s1[i] - 'a']++;
            count[s2[i] - 'a']--;
        }
        for (int item : count) {
            if (item != 0) {
                return false;
            }
        }
        for (int i = 1; i < length; i++) {
            if (isScramble(s1.substr(0, i), s2.substr(0, i)) && isScramble(s1.substr(i), s2.substr(i))) {
                return true;
            }
            if (isScramble(s1.substr(0, i), s2.substr(length - i)) &&
                isScramble(s1.substr(i), s2.substr(0, length - i))) {
                return true;
            }
        }
        return false;
    }
};