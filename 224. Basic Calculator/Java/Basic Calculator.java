public class Solution {
    public int calculate(String s) {
        Stack<Integer> stack = new Stack<>();
        int result = 0;
        int current = 0;
        int sign = 1;
        for (char letter : s.toCharArray()) {
            if (Character.isDigit(letter)) {
                current = current * 10 + letter - '0';
            } else if (letter == '+' || letter == '-') {
                result += sign * current;
                current = 0;
                sign = letter == '+' ? 1 : -1;
            } else if (letter == '(') {
                stack.push(result);
                stack.push(sign);
                sign = 1;
                result = 0;
            } else if (letter == ')') {
                result += sign * current;
                result *= stack.pop();
                result += stack.pop();
                current = 0;
            }
        }
        result += sign * current;
        return result;
    }
}