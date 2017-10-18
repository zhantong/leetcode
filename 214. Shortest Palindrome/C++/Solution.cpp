class Solution {
public:
    string shortestPalindrome(string s) {
        string rev(s);
        reverse(rev.rbegin(), rev.rend());
        int length = s.length();
        for (int i = length; i >= 0; i--) {
            if (s.substr(0, i) == rev.substr(length - i)) {
                return rev.substr(0, length - i) + s;
            }
        }
        return "";
    }
};