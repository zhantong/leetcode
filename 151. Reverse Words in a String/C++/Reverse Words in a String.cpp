class Solution {
public:
    void reverseWords(string &s) {
        class Utils {
        public:
            void reverse(string &s, int i, int j) {
                while (i < j) {
                    char temp = s[i];
                    s[i] = s[j];
                    s[j] = temp;
                    i++;
                    j--;
                }
            }
        };
        int i = 0;
        int j = 0;
        while (j < s.length() && s[j] == ' ') {
            j++;
        }
        while (j < s.length()) {
            if (s[j] != ' ' || (s[j] == ' ' && j < s.length() - 1 && s[j + 1] != ' ')) {
                s[i] = s[j];
                i++;
            }
            j++;
        }
        int length = i;
        Utils utils;
        utils.reverse(s, 0, length - 1);
        i = 0;
        for (j = 0; j < length; j++) {
            if (j + 1 == length || s[j + 1] == ' ') {
                utils.reverse(s, i, j);
                i = j + 2;
            }
        }
        s.erase(s.begin() + length, s.end());
    }
};