public class Solution {
    public boolean isValid(String s) {
        Stack<Character> stack = new Stack<>();
        for (char item : s.toCharArray()) {
            if (item == '(' || item == '{' || item == '[') {
                stack.add(item);
            } else if (stack.empty() && (item == ')' || item == '}' || item == ']')) {
                return false;
            } else if (item == ')') {
                if (stack.peek() == '(') {
                    stack.pop();
                } else {
                    return false;
                }
            } else if (item == '}') {
                if (stack.peek() == '{') {
                    stack.pop();
                } else {
                    return false;
                }
            } else if (item == ']') {
                if (stack.peek() == '[') {
                    stack.pop();
                } else {
                    return false;
                }
            }
        }
        return stack.empty();
    }
}