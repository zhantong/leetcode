class Solution {
public:
    int countSegments(string s) {
        int result = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != ' ' && (i == 0 || s[i - 1] == ' ')) {
                result++;
            }
        }
        return result;
    }
};