class Solution {
public:
    int calculate(string s) {
        int result = 0;
        int preNumber = 0;
        char preOperator = '+';
        int i = 0;
        while (i < s.length()) {
            while (i < s.length() && s[i] == ' ') {
                i++;
            }
            int current = 0;
            while (i < s.length() && s[i] >= '0' && s[i] <= '9') {
                current = current * 10 + s[i] - '0';
                i++;
            }
            switch (preOperator) {
            case '+':
                result += preNumber;
                preNumber = current;
                break;
            case '-':
                result += preNumber;
                preNumber = -current;
                break;
            case '*':
                preNumber *= current;
                break;
            case '/':
                preNumber /= current;
                break;
            }
            while (i < s.length() && s[i] == ' ') {
                i++;
            }
            if (i < s.length()) {
                preOperator = s[i];
                i++;
            }
        }
        result += preNumber;
        return result;
    }
};