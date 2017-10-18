class Solution {
public:
    vector<string> generateParenthesis(int n) {
        class Utils {
        public:
            void parenthesis(vector<string> &result, string current, int left, int right) {
                if (left == 0 && right == 0) {
                    result.push_back(current);
                } else if (left >= 0 && right >= left) {
                    parenthesis(result, current + "(", left - 1, right);
                    parenthesis(result, current + ")", left, right - 1);
                }
            }
        };
        vector<string> result;
        Utils utils;
        utils.parenthesis(result, "", n, n);
        return result;
    }
};