class Solution {
public:
    int minCut(string s) {
        int length = s.length();
        vector<int> cuts(length, 0);
        vector<vector<bool>> palindrome(length, vector<bool>(length, false));
        for (int i = 0; i < length; i++) {
            int current = i;
            for (int j = 0; j <= i; j++) {
                if (s[i] == s[j] && (i - j < 2 || palindrome[j + 1][i - 1])) {
                    palindrome[j][i] = true;
                    current = j == 0 ? 0 : min(current, cuts[j - 1] + 1);
                }
            }
            cuts[i] = current;
        }
        return cuts[length - 1];
    }
};