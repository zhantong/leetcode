public class Solution {
    public int calculate(String s) {
        int result = 0;
        int preNumber = 0;
        char preOperator = '+';
        int i = 0;
        while (i < s.length()) {
            while (i < s.length() && s.charAt(i) == ' ') {
                i++;
            }
            int current = 0;
            while (i < s.length() && s.charAt(i) >= '0' && s.charAt(i) <= '9') {
                current = current * 10 + s.charAt(i) - '0';
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
            while (i < s.length() && s.charAt(i) == ' ') {
                i++;
            }
            if (i < s.length()) {
                preOperator = s.charAt(i);
                i++;
            }
        }
        result += preNumber;
        return result;
    }
}