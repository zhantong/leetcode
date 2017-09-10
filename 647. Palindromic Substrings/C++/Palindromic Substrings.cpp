class Solution {
public:
    int countSubstrings(string s) {
        class Utils {
        public:
            int result = 0;

            void count(string &s, int left, int right) {
                while (left >= 0 && right < s.length() && s[left] == s[right]) {
                    result++;
                    left--;
                    right++;
                }
            }
        };
        Utils utils;
        for (int i = 0; i < s.length(); i++) {
            utils.count(s, i, i);
            utils.count(s, i, i + 1);
        }
        return utils.result;
    }
};