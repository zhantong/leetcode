class Solution {
public:
    int calculate(string s) {
        stack<int> sta;
        int result = 0;
        int current = 0;
        int sign = 1;
        for (auto letter : s) {
            if (isdigit(letter)) {
                current = current * 10 + letter - '0';
            } else if (letter == '+' || letter == '-') {
                result += sign * current;
                current = 0;
                sign = letter == '+' ? 1 : -1;
            } else if (letter == '(') {
                sta.push(result);
                sta.push(sign);
                sign = 1;
                result = 0;
            } else if (letter == ')') {
                result += sign * current;
                result *= sta.top();
                sta.pop();
                result += sta.top();
                sta.pop();
                current = 0;
            }
        }
        result += sign * current;
        return result;
    }
};