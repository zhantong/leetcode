class Solution {
public:
    string reverseStr(string s, int k) {
        class Utils {
        public:
            void reverse(string &str, int start, int end) {
                while (start < end) {
                    char temp = str[start];
                    str[start] = str[end];
                    str[end] = temp;
                    start++;
                    end--;
                }
            }
        };
        Utils utils;
        int length = s.length();
        for (int i = 0; i < length; i += 2 * k) {
            if (i + k >= length) {
                utils.reverse(s, i, length - 1);
            } else {
                utils.reverse(s, i, i + k - 1);
            }
        }
        return s;
    }
};