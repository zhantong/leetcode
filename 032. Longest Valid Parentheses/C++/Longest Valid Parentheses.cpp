class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> sta;
        int result = 0;
        int left = -1;
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(') {
                sta.push(i);
            } else {
                if (sta.empty()) {
                    left = i;
                } else {
                    sta.pop();
                    result = max(result, i - (sta.empty() ? left : sta.top()));
                }
            }
        }
        return result;
    }
};