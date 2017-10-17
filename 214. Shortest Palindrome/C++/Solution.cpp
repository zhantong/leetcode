class Solution {
public:
    string shortestPalindrome(string s) {
        string rev(s);
        reverse(rev.rbegin(), rev.rend());
        for (int i = 0; i < s.length(); i++) {
            if (s.find(rev.substr(i)) == 0) {
                return rev.substr(0, i) + s;
            }
        }
        return "";
    }
};