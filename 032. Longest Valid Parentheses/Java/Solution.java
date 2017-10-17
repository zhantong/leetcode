public class Solution {
    public int longestValidParentheses(String s) {
        Stack<Integer> stack = new Stack<>();
        int result = 0;
        int left = -1;
        for (int i = 0; i < s.length(); i++) {
            if (s.charAt(i) == '(') {
                stack.push(i);
            } else {
                if (stack.empty()) {
                    left = i;
                } else {
                    stack.pop();
                    result = Math.max(result, i - (stack.empty() ? left : stack.peek()));
                }
            }
        }
        return result;
    }
}