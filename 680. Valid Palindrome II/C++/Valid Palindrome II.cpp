class Solution {
public:
    bool validPalindrome(string s) {
        class Utils {
        public:
            bool isPalindrome(string &s, int left, int right) {
                while (left < right) {
                    if (s[left] != s[right]) {
                        return false;
                    }
                    left++;
                    right--;
                }
                return true;
            }
        };
        int left = 0;
        int right = s.length() - 1;
        Utils utils;
        while (left < right) {
            if (s[left] != s[right]) {
                return utils.isPalindrome(s, left + 1, right) || utils.isPalindrome(s, left, right - 1);
            }
            left++;
            right--;
        }
        return true;
    }
};