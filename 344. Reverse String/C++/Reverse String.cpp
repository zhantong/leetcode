class Solution {
public:
    string reverseString(string s) {
        for (int i = 0, j = s.length() - 1; i < j; i++, j--) {
            char temp = s[i];
            s[i] = s[j];
            s[j] = temp;
        }
        return s;
    }
};